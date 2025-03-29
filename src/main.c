#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// ウィンドウサイズ
#define WIDTH 960
#define HEIGHT 540

// ジュリア集合のパラメータ
#define MAX_ITERATIONS 100
#define INITIAL_ZOOM 1.0

typedef struct s_complex {
    double real;
    double imag;
} t_complex;

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    void    *mlx;
    void    *win;
    t_complex c;
    double  zoom;
    double  center_x;
    double  center_y;
} t_data;

// ピクセルに色を設定する関数
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// 複素数の二乗を計算
t_complex complex_square(t_complex z)
{
    t_complex result;
    
    result.real = z.real * z.real - z.imag * z.imag;
    result.imag = 2 * z.real * z.imag;
    return (result);
}

// 複素数の加算
t_complex complex_add(t_complex z1, t_complex z2)
{
    t_complex result;
    
    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return (result);
}

// 複素数の絶対値の二乗を計算
double complex_abs_squared(t_complex z)
{
    return (z.real * z.real + z.imag * z.imag);
}

// ジュリア集合の繰り返し計算
int julia_iterations(t_complex z, t_complex c)
{
    int i;
    
    i = 0;
    while (i < MAX_ITERATIONS && complex_abs_squared(z) < 4.0)
    {
        z = complex_add(complex_square(z), c);
        i++;
    }
    return (i);
}

// 反復回数から色を取得
int get_color(int iterations)
{
    if (iterations == MAX_ITERATIONS)
        return (0x000000); // 黒
    
    // HSVからRGBへの変換（簡易版）
    float hue = (float)iterations / MAX_ITERATIONS * 360.0;
    float s = 0.8;
    float v = iterations < MAX_ITERATIONS ? 1.0 : 0;
    
    float c = v * s;
    float x = c * (1 - fabs(fmod(hue / 60.0, 2) - 1));
    float m = v - c;
    
    float r, g, b;
    
    if (hue >= 0 && hue < 60) { r = c; g = x; b = 0; }
    else if (hue >= 60 && hue < 120) { r = x; g = c; b = 0; }
    else if (hue >= 120 && hue < 180) { r = 0; g = c; b = x; }
    else if (hue >= 180 && hue < 240) { r = 0; g = x; b = c; }
    else if (hue >= 240 && hue < 300) { r = x; g = 0; b = c; }
    else { r = c; g = 0; b = x; }
    
    int red = (r + m) * 255;
    int green = (g + m) * 255;
    int blue = (b + m) * 255;
    
    return ((red << 16) | (green << 8) | blue);
}

// ジュリア集合を描画する関数
void draw_julia(t_data *data)
{
    int x, y;
    t_complex z;
    int iterations;
    int color;
    
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // スクリーン座標から複素平面座標への変換（ズームとセンタリングを考慮）
            z.real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom) + data->center_x;
            z.imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom) + data->center_y;
            
            // ジュリア集合の計算
            iterations = julia_iterations(z, data->c);
            
            // 色の計算と設定
            color = get_color(iterations);
            my_mlx_pixel_put(data, x, y, color);
            
            x++;
        }
        y++;
    }
}

// 画面を再描画
void redraw(t_data *data)
{
    // 古い画像を破棄
    mlx_destroy_image(data->mlx, data->img);
    
    // 新しい画像を作成
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    
    // 新しいパラメータでジュリア集合を描画
    draw_julia(data);
    
    // 画面に表示
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

// マウスホイールイベント処理
int mouse_hook(int button, int x, int y, t_data *data)
{
    // 座標を計算して保存（ズーム前の複素平面上の位置）
    double real_before = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom) + data->center_x;
    double imag_before = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom) + data->center_y;
    
    // ズームイン（スクロールアップ、ボタン4）
    if (button == 4)
    {
        data->zoom *= 1.2;
    }
    // ズームアウト（スクロールダウン、ボタン5）
    else if (button == 5 && data->zoom > 0.1)
    {
        data->zoom /= 1.2;
    }
    
    // マウス位置を中心にズーム
    if (button == 4 || button == 5)
    {
        // 座標を再計算（ズーム後）
        double real_after = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom) + data->center_x;
        double imag_after = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom) + data->center_y;
        
        // 差分を中心座標に適用
        data->center_x += (real_before - real_after);
        data->center_y += (imag_before - imag_after);
        
        // 再描画
        redraw(data);
    }
    
    return (0);
}

// キー入力処理
int key_hook(int keycode, t_data *data)
{
    if (keycode == 65307) // ESCキー
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return (0);
}

// ウィンドウを閉じる処理
int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int main(void)
{
    t_data data;
    
    // MinilibXの初期化
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Julia Set");
    
    // 画像の作成
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    
    // ジュリア集合のパラメータ設定
    data.c.real = -0.7; // -0.7 + 0.27015i は美しいジュリア集合を生成
    data.c.imag = 0.27015;
    data.zoom = INITIAL_ZOOM;
    data.center_x = 0.0;
    data.center_y = 0.0;
    
    // ジュリア集合の描画
    draw_julia(&data);
    
    // 画像の表示
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    
    // イベントハンドラの設定
    mlx_key_hook(data.win, key_hook, &data);
    mlx_mouse_hook(data.win, mouse_hook, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    
    // イベントループの開始
    mlx_loop(data.mlx);
    
    return (0);
}
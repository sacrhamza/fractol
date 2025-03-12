#include <mlx.h>
#include <stdlib.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
	int i;
} t_data;

int close_win(t_data *data) {
    mlx_destroy_window(data->mlx, data->win);
    mlx_loop_end(data->mlx);
    return (0);
}

int main(void) {
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, 640, 480, "Close Window Example");
    if (!data.win) {
        mlx_destroy_display(data.mlx);
        free(data.mlx);
        return (1);
    }
    mlx_hook(data.win, 17, 0, close_win, &data);
    mlx_loop(data.mlx);
    mlx_destroy_display(data.mlx);
    free(data.mlx);
    return (0);
}

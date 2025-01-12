#include "mlx.h"
#include <stdio.h>
#include<stddef.h>
#include<stdlib.h>
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define ZOOM_FACTOR 1.1

typedef struct s_data {
    void    *mlx;
    void    *win;
    double  zoom;
} t_data;

int zoom_in(int button, int x, int y, t_data *data)
{
    if (button == 4) // Scroll up
        data->zoom *= ZOOM_FACTOR;
    else if (button == 5) // Scroll down
        data->zoom /= ZOOM_FACTOR;

    // For debugging: print zoom level
    printf("Zoom level: %.2f\n", data->zoom);

    // Clear window and redraw with new zoom level
    mlx_clear_window(data->mlx, data->win);
    
    // Call your drawing function and apply zoom here.
    // e.g., draw_scene_with_zoom(data->zoom);

    return 0; // Return an integer as expected by mlx_mouse_hook
}

int main()
{
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx)
        return 1;
    
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Zoom Window");
    if (!data.win)
        return 1;

    data.zoom = 1.0;  // Initial zoom level

    // Register the mouse scroll event
    mlx_mouse_hook(data.win, zoom_in, &data);

    // Start the mlx event loop
    mlx_loop(data.mlx);

    return 0;
}

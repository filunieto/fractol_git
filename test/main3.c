#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 720
#define HEIGHT 480


/**
 * Callback function used to handle scrolling.
 * 
 * @param[in] x The mouse x delta.
 * @param[in] y The mouse y delta.
 * @param[in] param Additional parameter to pass onto the function.
 */
typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);

/**
 * This function sets the scroll callback, which is called when a scrolling 
 * device is used, such as a mouse wheel.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The scroll wheel callback function.
 * @param[in] param An additional optional parameter.
 */
void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param);


/**
 * Callback function used to handle window closing which is called when the user attempts 
 * to close the window, for example by clicking the close widget in the title bar.
 * 
 * @param[in] param Additional parameter to pass onto the function.
 */
typedef void (*mlx_closefunc)(void* param);

/**
 * This function sets the close callback, which is called in attempt to close 
 * the window device such as a close window widget used in the window bar.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The close callback function.
 * @param[in] param An additional optional parameter.
 */
void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param);


/**
 * Callback function used to handle window resizing.
 * 
 * @param[in] width The new width of the window.
 * @param[in] height The new height of the window. 
 * @param[in] param Additional parameter to pass onto the function.
 */
typedef void (*mlx_resizefunc)(int32_t width, int32_t height, void* param);

/**
 * This function sets the resize callback, which is called when the window is
 * resized
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The resize callback function.
 * @param[in] param An additional optional parameter.
 */

void mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param);
/**
 * Key function callback data.
 * Data related the mlx_key_hook function
 * 
 * @param key The key that was pressed.
 * @param action The action that was done with the key.
 * @param os_key The os_key is unique for every key, and will have a 
 * different value/keycode depending on the platform. 
 * They may be consistent on different platforms.
 * @param modifier The modifier key that was pressed, 0 if none.
 */

// typedef struct mlx_key_data
// {
// 	keys_t		key;
// 	action_t	action;
// 	int32_t		os_key;
// 	modifier_key_t	modifier;
// }	mlx_key_data_t;


/**
 * Callback function used to handle key presses.
 * 
 * @param[in] keydata The callback data, contains info on key, action, ...
 * @param[in] param Additional parameter to pass onto the function.
 */
typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param);

/**
 * This function sets the key callback, which is called when a key is pressed
 * on the keyboard. Useful for single key press detection.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The key press callback function.
 * @param[in] param An additional optional parameter.
 */
void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);

/**
 * Generic loop hook for any custom hooks to add to the main loop. 
 * Executes a function per frame, so be careful.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] f The function.
 * @param[in] param The parameter to pass onto the function.
 * @returns Wether the hook was added successfuly. 
 */
bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);



void my_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	
	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

int32_t	main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);

	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:24:11 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 00:20:01 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H //REvisar si necesito todo

# define KEYS_H

/* *****************MAC_OS KEY HOOKS ***************** */

//EVENTS (BUILD IN INTERFACE ELEMENTS (e.g: red cross to close a window))
# define EVENT_CLOSE_BTN 17

// MOUSE HOOKS
// # define ZOOM_IN	5
// # define ZOOM_OUT	4

/*
// mouse button codes
*/

# define MOUSE_UP		4
# define MOUSE_DOWN		5
# define RIGHT_CLICK 2
# define LEFT_CLICK 1
# define MOUSE_WHEEL 3


//ARROW KEYS HOOKS
// typedef enum s_arrows
// {
// 	LEFT = 123,
// 	RIGHT,
// 	DOWN,
// 	UP,
// }	t_arrows;


//KEYBOARD HOOKS
# define ESC 		53

//PRESETS KEYS
# define ONE 		18
# define TWO 		19
# define THREE		20
# define FOUR 		21
# define FIVE 		23
# define SIX 		22
# define SEVEN		26
# define EIGHT		28
# define NINE 		25
# define ZERO 		29

//ARROW KEYS HOOKS
# define UP 		126
# define DOWN 		125
# define LEFT 		124
# define RIGHT		123

//FRACTAL HOTKEYS
# define J 			38
# define B 			11

//COLOR RANGE INCREASE/DECREASE KEY HOOKS
# define Q 			12
# define W 			13
# define E 			14
# define A 			0
# define S 			1
# define D 			2

//INFO PRINTERS
# define C 			8
# define K 			40
# define I 			34
# define H 			4


#endif
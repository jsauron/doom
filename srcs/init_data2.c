/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:02:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/09/21 19:02:36 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_keys(t_game *game)
{
	if (!(game->keys[0] = IMG_Load("ressources/key.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[1] = IMG_Load("ressources/key2.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[2] = IMG_Load("ressources/key3.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[3] = IMG_Load("ressources/key6.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[4] = IMG_Load("ressources/key7.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->keys[5] = IMG_Load("ressources/key8.png")))
		ft_err_exit("doom: error: bad textures", game);
}

void	init_hud(t_game *game)
{
	if (!(game->heart[0] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->heart[1] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->heart[2] = IMG_Load("ressources/heart.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->hit_contact = IMG_Load("ressources/coutour_hit.png")))
		ft_err_exit("doom: error: bad textures hit contact", game);
}

void	init_win_menu(t_game *game)
{
	if (!(game->win[0] = IMG_Load("ressources/win2.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[1] = IMG_Load("ressources/win3.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[2] = IMG_Load("ressources/win4.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[3] = IMG_Load("ressources/win5.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[4] = IMG_Load("ressources/win6.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[5] = IMG_Load("ressources/win7.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[6] = IMG_Load("ressources/win8.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[7] = IMG_Load("ressources/win9.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[8] = IMG_Load("ressources/win10.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[9] = IMG_Load("ressources/win11.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[10] = IMG_Load("ressources/win12.tga")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->win[11] = IMG_Load("ressources/win13.tga")))
		ft_err_exit("doom: error: bad textures", game);
}

void	init_poster(t_game *game)
{
	if (!(game->poster[0] = IMG_Load("ressources/wall/poster1.tga")))
		ft_err_exit("doom: error: bad textures p1", game);
	if (!(game->poster[1] = IMG_Load("ressources/wall/poster2.tga")))
		ft_err_exit("doom: error: bad textures p2", game);
	if (!(game->poster[2] = IMG_Load("ressources/wall/poster3.tga")))
		ft_err_exit("doom: error: bad textures p3", game);
	if (!(game->poster[3] = IMG_Load("ressources/wall/poster4.tga")))
		ft_err_exit("doom: error: bad textures p4", game);
}

void	init_weapon(t_game *game)
{
	if (!(game->weapon[0] = IMG_Load("ressources/arme_3.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->weapon[1] = IMG_Load("ressources/arme_tir.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->lunette[0] = IMG_Load("ressources/lunette.png")))
		ft_err_exit("doom: error: bad textures", game);
	if (!(game->lunette[1] = IMG_Load("ressources/lunette_tir.png")))
		ft_err_exit("doom: error: bad textures", game);
}

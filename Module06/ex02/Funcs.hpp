/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:39:40 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/12 23:59:35 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
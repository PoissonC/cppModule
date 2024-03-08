/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:39:35 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/08 11:55:33 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main() {
	AMateria *floor;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	ICharacter* mike = new Character("mike");
	{
		Character copy_of_me(*(Character*)me);
		copy_of_me.use(1, *mike);
		copy_of_me.unequip(1);
	}
	me->use(1, *bob);
	me->unequip(1);
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(1, *bob);
	{
		Character copy_of_me = *(Character*)me;
		copy_of_me.use(0, *mike);
		copy_of_me.use(2, *mike);
		copy_of_me.unequip(2);
		copy_of_me.use(2, *mike);
		floor = copy_of_me.getInventory(3);
		copy_of_me.unequip(3);
		delete floor;
	}

	delete mike;
	delete bob;
	delete me;
	delete src;
	return 0;
}
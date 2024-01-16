/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/16 15:37:02 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int main( void ) {
	IMateriaSource* src = new MateriaSource(); src->learnMateria(new Ice()); src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice"); me->equip(tmp);
	tmp = src->createMateria("cure"); me->equip(tmp);
	ICharacter* bob = new Character("bob"); me->use(0, *bob);
	me->use(1, *bob);
	delete bob; delete me; delete src;

	return 0;
}

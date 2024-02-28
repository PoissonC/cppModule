/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:19:01 by ychen2            #+#    #+#             */
/*   Updated: 2024/02/27 23:11:14 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
	private:
		AMateria*	_inventory[4];
		bool		_iused[4];
		std::string	_name;
	public:
		Character(const std::string& name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

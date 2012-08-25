/**
 * @file	paddle_ai.h
 * @author  Jason White <jason@jswhite.net> <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * Created on August 25, 2012, 6:48 PM
 *
 * @section LICENSE
 *
 * PONG - The open source pong clone Copyright (C) 2012 Jason White, White Waters Software
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see http://www.gnu.org/licenses/.
 *
 * @section DESCRIPTION
 *
 *
 */

#ifndef PADDLE_AI_H
#define	PADDLE_AI_H
#include "game_engine.h"

class paddle_ai : public controller
{
public:
	paddle_ai();
	paddle_ai(const paddle_ai& orig);
	virtual ~paddle_ai();
private:

} ;

#endif	/* PADDLE_AI_H */


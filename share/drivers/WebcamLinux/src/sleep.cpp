// Carnival LiveCam, Augmented reality made easy.
// Copyright (C) 2011-2012  Gonzalo Exequiel Pedone
//
// Carnival LiveCam is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Carnival LiveCam is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Carnival LiveCam.  If not, see <http://www.gnu.org/licenses/>.
//
// Email   : hipersayan DOT x AT gmail DOT com
// Web-Site: https://github.com/hipersayanX/Carnival-LiveCam

#include "../include/sleep.h"

/*!
  \class Sleep

  \brief This class stop the program execution by a desired amount of time.
 */

/*!
  \fn void Sleep::usleep(unsigned long usecs)

  \param usecs Micro seconds.

  \brief Causes the program to sleep for \i usecs milliseconds.
 */
void Sleep::usleep(unsigned long usecs)
{
    QThread::usleep(usecs);
}

/*!
  \fn void Sleep::msleep(unsigned long msecs)

  \param msecs Mili seconds.

  \brief Causes the program to sleep for \i msecs milliseconds.
 */
void Sleep::msleep(unsigned long msecs)
{
    QThread::msleep(msecs);
}

/*!
  \fn void Sleep::sleep(unsigned long secs)

  \param secs Seconds.

  \brief Causes the program to sleep for \i secs milliseconds.
 */
void Sleep::sleep(unsigned long secs)
{
    QThread::sleep(secs);
}

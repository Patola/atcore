/* AtCore KDE Libary for 3D Printers
    Copyright (C) <2016>

    Authors:
        Tomaz Canabrava <tcanabrava@kde.org>
        Chris Rizzitello <sithlord48@gmail.com>
        Patrick José Pereira <patrickelectric@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include "ifirmware.h"
#include <QObject>

class MarlinPlugin : public IFirmware
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.kde.atelier.core.firmware" FILE "marlin.json")
    Q_INTERFACES(IFirmware)
private:
    static QString _ok;
    static QString _extruderTemp;
    static QString _bedTemp;
    float _lastBedTemp;
    float _lastExtruderTemp;
    float _lastTargetBedTemp;
    float _lastTargetExtruderTemp;
public:
    MarlinPlugin();
    QString name() const override;
    void extractTemp(const QString &lastMessage);
    void validateCommand(const QString &lastMessage);
    QByteArray translate(const QString &command) override;
};

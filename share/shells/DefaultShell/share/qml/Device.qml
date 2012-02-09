/*
 * Carnival LiveCam, Augmented reality made easy.
 * Copyright (C) 2011  Gonzalo Exequiel Pedone
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with This program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Email   : hipersayan DOT x AT gmail DOT com
 * Web-Site: http://hipersayanx.blogspot.com/
 *
 * QML shell plugin
 */

import QtQuick 1.1

Rectangle
{
    id: recDevice
    width: 256
    height: 32
    color: "#00000000"
    radius: 10
    clip: true

    property string deviceId: ""
    property string driverId: ""
    property bool isEnabled: false
    property string summary: ""
    property string icon: ""
    property bool isConfigurable: false
    property color borderColorNormal: "#00000000"
    property color borderColorHover: "#7f7fff"
    property color borderColorPressed: "#ffffff"
    property bool moving: false

    signal clicked
    signal configure
    signal enteredMove
    signal beginMove(int mouseX, int mouseY)
    signal move(int mouseX, int mouseY)
    signal endMove
    signal exitedMove

    Rectangle
    {
        id: recHighlight
        radius: 10
        visible: recDevice.isEnabled
        anchors.fill: parent

        gradient: Gradient
        {
            GradientStop
            {
                position: 0
                color: "#007fff"
            }

            GradientStop
            {
                position: 1
                color: "#000000"
            }
        }
    }

    Image
    {
        id: imgIcon
        width: recDevice.height
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        source: recDevice.icon
    }

    Text
    {
        id: txtSummary
        color: "#ffffff"
        text: recDevice.summary
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle
    {
        id: recHoverHighlight
        color: "#00000000"
        radius: 10
        anchors.fill: parent
        border.width: 2
        border.color: recDevice.borderColorNormal
    }

    MouseArea
    {
        id: msaDevice
        anchors.fill: parent
        hoverEnabled: true

        onClicked: recDevice.clicked()
        onEntered: recHoverHighlight.border.color = recDevice.borderColorHover
        onExited: recHoverHighlight.border.color = recDevice.borderColorNormal
        onPressed: recHoverHighlight.border.color = recDevice.borderColorPressed
        onReleased: recHoverHighlight.border.color = recDevice.borderColorHover
    }

    Button
    {
        id: btnConfigure
        visible: recDevice.isConfigurable && recDevice.isEnabled
        width: recDevice.height - 4
        anchors.rightMargin: 2
        anchors.bottomMargin: 2
        anchors.topMargin: 2
        icon: "../images/icons/configure.svg"
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.right: btnMove.left

        onClicked: recDevice.configure()
        onEntered: recHoverHighlight.border.color = recDevice.borderColorHover
        onExited: recHoverHighlight.border.color = recDevice.borderColorNormal
    }

    Button
    {
        id: btnMove
        visible: recDevice.isEnabled
        width: recDevice.height - 4
        anchors.rightMargin: 2
        anchors.bottomMargin: 2
        anchors.topMargin: 2
        icon: "../images/icons/move.svg"
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.right: parent.right

        onEntered:
        {
            recHoverHighlight.border.color = recDevice.borderColorHover
            recDevice.enteredMove()
        }

        onExited:
        {
            recHoverHighlight.border.color = recDevice.borderColorNormal
            recDevice.exitedMove()
        }

        onPressed:
        {
            recDevice.beginMove(btnMove.mouseX, btnMove.mouseY)
            recDevice.moving = true
        }

        onPositionChanged:
        {
            if (recDevice.moving)
                recDevice.move(btnMove.mouseX, btnMove.mouseY)
        }

        onReleased:
        {
            if (recDevice.moving)
            {
                recDevice.moving = false
                recDevice.endMove()
            }
        }
    }
}

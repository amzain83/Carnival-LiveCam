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
    id: recListWidget
    width: 512
    height: 128
    radius: 8
    smooth: true
    border.width: 1
    border.color: "#7f7f7f"
    property real minHeight: 24
    property real maxHeight: 32768

    gradient: Gradient
    {
        GradientStop
        {
            position: 0
            color: "#3f3f3f"
        }

        GradientStop
        {
            position: 1
            color: "#000000"
        }
    }

    function setIndex(index)
    {
        lsvOptions.currentIndex = index
    }

    function updateOptions(newOptions)
    {
        lsmOptions.clear()

        for(var option in newOptions)
            lsmOptions.append({"option": newOptions[option]})

        lsvOptions.currentIndex = 0
        recListWidget.updateHeight()
    }

    function updateHeight()
    {
        if (!lsvOptions.currentItem)
            return;

        lsvOptions.contentHeight = lsvOptions.currentItem.children[0].height * lsvOptions.count

        if (lsvOptions.contentHeight <= recListWidget.maxHeight)
        {
            if (lsvOptions.contentHeight >= recListWidget.minHeight)
                recListWidget.height = lsvOptions.contentHeight
            else
                recListWidget.height = recListWidget.minHeight
        }
        else
            recListWidget.height = recListWidget.maxHeight

        recListWidget.height *= 1.1
    }

    signal itemSelected(int index, string value)
    signal escapePressed

    Component.onCompleted: recListWidget.updateHeight()

    ListView
    {
        id: lsvOptions
        snapMode: ListView.SnapToItem
        anchors.leftMargin: 1
        anchors.bottomMargin: 1
        anchors.topMargin: 1
        clip: true
        anchors.right: sldScroll.left
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        focus: true

        highlight: Rectangle
        {
            id: recHighlight
            width: lsvOptions.width
            radius: recListWidget.radius
            smooth: true

            Behavior on y
            {
                SpringAnimation
                {
                    spring: 0
                    damping: 0
                }
            }

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

        delegate: Item
        {
            Row
            {
                Text
                {
                    width: lsvOptions.width
                    text: option
                    color: "#ffffff"
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    Component.onCompleted: parent.parent.height = height

                    MouseArea
                    {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: parent.font.bold = true
                        onExited: parent.font.bold = false
                    }
                }
            }
        }

        model: ListModel
        {
            id: lsmOptions
        }

        Keys.onDownPressed:
        {
            lsvOptions.incrementCurrentIndex()
            var tmpValue = Math.round(lsvOptions.contentY * (sldScroll.maxValue - sldScroll.minValue) / lsvOptions.height + sldScroll.minValue)
            sldScroll.setValue(tmpValue)
        }

        Keys.onUpPressed:
        {
            lsvOptions.decrementCurrentIndex()
            var tmpValue = Math.round(lsvOptions.contentY * (sldScroll.maxValue - sldScroll.minValue) / lsvOptions.height + sldScroll.minValue)
            sldScroll.setValue(tmpValue)
        }

        Keys.onEnterPressed: if (lsvOptions.currentItem) recListWidget.itemSelected(currentIndex, lsvOptions.currentItem.children[0].children[0].text)
        Keys.onReturnPressed: if (lsvOptions.currentItem) recListWidget.itemSelected(currentIndex, lsvOptions.currentItem.children[0].children[0].text)
        Keys.onEscapePressed: recListWidget.escapePressed()

        onMovementEnded:
        {
            var tmpValue = Math.round(lsvOptions.contentY * (sldScroll.maxValue - sldScroll.minValue) / lsvOptions.height + sldScroll.minValue)
            sldScroll.setValue(tmpValue)
        }

        MouseArea
        {
            id: msaOptions
            anchors.fill: parent

            onClicked:
            {
                if (lsvOptions.count <= 0)
                    return

                var index = Math.floor((lsvOptions.contentY + mouseY) * (lsvOptions.count / lsvOptions.contentHeight))

                if (index > lsvOptions.count)
                    index = lsvOptions.count - 1

                lsvOptions.currentIndex = index

                if (lsvOptions.currentItem)
                    recListWidget.itemSelected(index, lsvOptions.currentItem.children[0].children[0].text)
            }
        }
    }

    Slider
    {
        id: sldScroll
        showUpDown: true
        anchors.bottomMargin: 1
        anchors.topMargin: 1
        anchors.rightMargin: 1
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.right: parent.right

        function updateValue()
        {
            var tmpNewMaxValue = Math.ceil(lsvOptions.contentHeight / lsvOptions.height - 1)

            if (tmpNewMaxValue < sldScroll.minValue)
                sldScroll.maxValue = sldScroll.minValue
            else
                sldScroll.maxValue = tmpNewMaxValue

            var newValue = sldScroll.minValue

            if (sldScroll.maxValue != sldScroll.minValue)
            {
                var k = (tmpNewMaxValue - sldScroll.minValue) / (sldScroll.maxValue - sldScroll.minValue)
                newValue = Math.ceil(k * (sldScroll.value - sldScroll.minValue) + sldScroll.minValue)
            }

            sldScroll.setValue(newValue)
            sldScroll.visible = sldScroll.maxValue > sldScroll.minValue? true: false
            sldScroll.width = sldScroll.visible? 16: 0
        }

        onHeightChanged: updateValue()
        Component.onCompleted: updateValue()

        onValueChanged:
        {
            var index = Math.ceil((value - sldScroll.minValue) * (lsvOptions.count - 1) / (sldScroll.maxValue - sldScroll.minValue))
            lsvOptions.positionViewAtIndex(index, ListView.Beginning)
        }
    }
}

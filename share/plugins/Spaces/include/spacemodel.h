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

#ifndef SPACEMODEL_H
#define SPACEMODEL_H

#include <QObject>

#include "space.h"

class SpaceModel: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString currentSelectedSpace READ currentSelectedSpace WRITE setCurrentSelectedSpace RESET resetCurrentSelectedSpace)
    Q_PROPERTY(QRectF rect READ rect WRITE setRect RESET resetRect)
    Q_PROPERTY(QList<Space> spaces READ spaces WRITE setSpaces RESET resetSpaces)
    Q_PROPERTY(bool snapping READ snapping WRITE setSnapping RESET resetSnapping)
    Q_PROPERTY(qint32 nParts READ nParts WRITE setNParts RESET resetNParts)
    Q_PROPERTY(qreal snappingPT READ snappingPT WRITE setSnappingPT RESET resetSnappingPT)
    Q_PROPERTY(qreal snappingRT READ snappingRT WRITE setSnappingRT RESET resetSnappingRT)

    public:
        explicit SpaceModel(QObject *parent = 0);
        Q_INVOKABLE void setSnapping(bool snapping, qint32 nParts, qreal snappingPT, qreal snappingRT);
        Q_INVOKABLE Space setSpace(QString spaceId, QSizeF size);
        Q_INVOKABLE void removeSpace(QString spaceId);
        Q_INVOKABLE void selectSpace(QString spaceId);
        Q_INVOKABLE void selectSpace(QPointF point);
        Q_INVOKABLE void toggleMaximizedSpace();
        Q_INVOKABLE bool isMaximized(QString spaceId);
        Q_INVOKABLE QSizeF spaceSize(QString spaceId);
        Q_INVOKABLE QPointF mapToLocal(QPointF point, QString *spaceId = NULL);

        QString currentSelectedSpace();
        QRectF rect();
        QList<Space> spaces();
        bool snapping();
        qint32 nParts();
        qreal snappingPT();
        qreal snappingRT();

    private:
        QString m_currentSelectedSpace;
        QRectF m_rect;
        QList<Space> m_spaces;
        QPointF m_pointRef;
        bool m_snapping;
        qint32 m_nParts;
        qreal m_snappingPT;
        qreal m_snappingRT;

        template <typename T> QList<T> removeDuplicates(QList<T> &list);
        template <typename T> void removeDuplicatesAndSort(QList<T> &list);
        template <typename T> QList<T> reversed(const QList<T> &list);
        template <typename T> bool snapLines(QList<T> &hLines, QList<T> &vLines);
        qreal calculateAngle(QPointF point);

    signals:
        void spaceMoved(qint32 from, qint32 to);

    public slots:
        void updateRect();
        void scaleAndRotateSpace(QPointF to);
        void moveSpace(QPointF to);
        void moveSpace(qint32 from, qint32 to);
        void setCurrentSelectedSpace(QString value);
        void setRect(QRectF value);
        void setSpaces(QList<Space> value);
        void setSnapping(bool value);
        void setNParts(qint32 value);
        void setSnappingPT(qreal value);
        void setSnappingRT(qreal value);
        void resetCurrentSelectedSpace();
        void resetRect();
        void resetSpaces();
        void resetSnapping();
        void resetNParts();
        void resetSnappingPT();
        void resetSnappingRT();
};

#endif // SPACEMODEL_H
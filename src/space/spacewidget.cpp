#include "../../include/space/spacewidget.h"

SpaceWidget::SpaceWidget(QWidget *parent): QWidget(parent)
{
    this->m_editMode = false;

    this->setObjectName("wdgSpaceWidget");
    this->setGeometry(0, 0, frame.width(), frame.height());

    this->spacePixmap.setGeometry(0, 0, frame.width(), frame.height());
    this->spacePixmap.setScaledContents(true);
    this->spacePixmap.setParent(this);

    this->spaceControls.setGeometry(0, 0, frame.width(), frame.height());
    this->spaceControls.setParent(this);
}

SpaceWidget::SpaceWidget(const QImage &frame)
{
    this->m_editMode = false;

    this->setObjectName("wdgSpaceWidget");
    this->setGeometry(0, 0, frame.width(), frame.height());

    this->spacePixmap.setGeometry(0, 0, frame.width(), frame.height());
    this->spacePixmap.setScaledContents(true);
    this->spacePixmap.setPixmap(QPixmap::fromImage(frame));
    this->spacePixmap.setParent(this);

    this->spaceControls.setGeometry(0, 0, frame.width(), frame.height());
    this->spaceControls.setParent(this);
}

bool SpaceWidget::editMode()
{
    return this->m_editMode;
}

void SpaceWidget::setEditMode(bool value)
{
    this->m_editMode = value;
}

void SpaceWidget::resetEditMode()
{
    this->m_editMode = false;
}

void SpaceWidget::setControlButtons(QPushButton *toggleMaximizedButton, QPushButton *scaleAndRotateButton)
{
    if (toggleMaximizedButton)
    {
        this->spaceControls.btnToggleMaximize->setAutoDefault(toggleMaximizedButton->autoDefault());
        this->spaceControls.btnToggleMaximize->setAutoExclusive(toggleMaximizedButton->autoExclusive());
        this->spaceControls.btnToggleMaximize->setAutoFillBackground(toggleMaximizedButton->autoFillBackground());
        this->spaceControls.btnToggleMaximize->setAutoRepeat(toggleMaximizedButton->autoRepeat());
        this->spaceControls.btnToggleMaximize->setAutoRepeatDelay(toggleMaximizedButton->autoRepeatDelay());
        this->spaceControls.btnToggleMaximize->setAutoRepeatInterval(toggleMaximizedButton->autoRepeatInterval());
        this->spaceControls.btnToggleMaximize->setBackgroundRole(toggleMaximizedButton->backgroundRole());
        this->spaceControls.btnToggleMaximize->setBaseSize(toggleMaximizedButton->baseSize());
        this->spaceControls.btnToggleMaximize->setCheckable(toggleMaximizedButton->isCheckable());
        this->spaceControls.btnToggleMaximize->setChecked(toggleMaximizedButton->isChecked());
        this->spaceControls.btnToggleMaximize->setContentsMargins(toggleMaximizedButton->contentsMargins());
        this->spaceControls.btnToggleMaximize->setCursor(toggleMaximizedButton->cursor());
        this->spaceControls.btnToggleMaximize->setDown(toggleMaximizedButton->isDown());
        this->spaceControls.btnToggleMaximize->setEnabled(toggleMaximizedButton->isEnabled());
        this->spaceControls.btnToggleMaximize->setFlat(toggleMaximizedButton->isFlat());
        this->spaceControls.btnToggleMaximize->setFont(toggleMaximizedButton->font());
        this->spaceControls.btnToggleMaximize->setForegroundRole(toggleMaximizedButton->foregroundRole());
        this->spaceControls.btnToggleMaximize->setGeometry(toggleMaximizedButton->geometry());
        this->spaceControls.btnToggleMaximize->setGraphicsEffect(toggleMaximizedButton->graphicsEffect());
        this->spaceControls.btnToggleMaximize->setHidden(toggleMaximizedButton->isHidden());
        this->spaceControls.btnToggleMaximize->setIcon(toggleMaximizedButton->icon());
        this->spaceControls.btnToggleMaximize->setIconSize(toggleMaximizedButton->iconSize());
        this->spaceControls.btnToggleMaximize->setMask(toggleMaximizedButton->mask());
        this->spaceControls.btnToggleMaximize->setMaximumHeight(toggleMaximizedButton->maximumHeight());
        this->spaceControls.btnToggleMaximize->setMaximumSize(toggleMaximizedButton->maximumSize());
        this->spaceControls.btnToggleMaximize->setMaximumWidth(toggleMaximizedButton->maximumWidth());
        this->spaceControls.btnToggleMaximize->setMinimumHeight(toggleMaximizedButton->minimumHeight());
        this->spaceControls.btnToggleMaximize->setMinimumSize(toggleMaximizedButton->minimumSize());
        this->spaceControls.btnToggleMaximize->setMinimumWidth(toggleMaximizedButton->minimumWidth());
        this->spaceControls.btnToggleMaximize->setSizePolicy(toggleMaximizedButton->sizePolicy());
        this->spaceControls.btnToggleMaximize->setStyle(toggleMaximizedButton->style());
        this->spaceControls.btnToggleMaximize->setStyleSheet(toggleMaximizedButton->styleSheet());
        this->spaceControls.btnToggleMaximize->setText(toggleMaximizedButton->text());
        this->spaceControls.btnToggleMaximize->setVisible(toggleMaximizedButton->isVisible());
    }

    if (scaleAndRotateButton)
    {
        this->spaceControls.btnScaleAndRotate->setAutoDefault(scaleAndRotateButton->autoDefault());
        this->spaceControls.btnScaleAndRotate->setAutoExclusive(scaleAndRotateButton->autoExclusive());
        this->spaceControls.btnScaleAndRotate->setAutoFillBackground(scaleAndRotateButton->autoFillBackground());
        this->spaceControls.btnScaleAndRotate->setAutoRepeat(scaleAndRotateButton->autoRepeat());
        this->spaceControls.btnScaleAndRotate->setAutoRepeatDelay(scaleAndRotateButton->autoRepeatDelay());
        this->spaceControls.btnScaleAndRotate->setAutoRepeatInterval(scaleAndRotateButton->autoRepeatInterval());
        this->spaceControls.btnScaleAndRotate->setBackgroundRole(scaleAndRotateButton->backgroundRole());
        this->spaceControls.btnScaleAndRotate->setBaseSize(scaleAndRotateButton->baseSize());
        this->spaceControls.btnScaleAndRotate->setCheckable(scaleAndRotateButton->isCheckable());
        this->spaceControls.btnScaleAndRotate->setChecked(scaleAndRotateButton->isChecked());
        this->spaceControls.btnScaleAndRotate->setContentsMargins(scaleAndRotateButton->contentsMargins());
        this->spaceControls.btnScaleAndRotate->setCursor(scaleAndRotateButton->cursor());
        this->spaceControls.btnScaleAndRotate->setDown(scaleAndRotateButton->isDown());
        this->spaceControls.btnScaleAndRotate->setEnabled(scaleAndRotateButton->isEnabled());
        this->spaceControls.btnScaleAndRotate->setFlat(scaleAndRotateButton->isFlat());
        this->spaceControls.btnScaleAndRotate->setFont(scaleAndRotateButton->font());
        this->spaceControls.btnScaleAndRotate->setForegroundRole(scaleAndRotateButton->foregroundRole());
        this->spaceControls.btnScaleAndRotate->setGeometry(scaleAndRotateButton->geometry());
        this->spaceControls.btnScaleAndRotate->setGraphicsEffect(scaleAndRotateButton->graphicsEffect());
        this->spaceControls.btnScaleAndRotate->setHidden(scaleAndRotateButton->isHidden());
        this->spaceControls.btnScaleAndRotate->setIcon(scaleAndRotateButton->icon());
        this->spaceControls.btnScaleAndRotate->setIconSize(scaleAndRotateButton->iconSize());
        this->spaceControls.btnScaleAndRotate->setMask(scaleAndRotateButton->mask());
        this->spaceControls.btnScaleAndRotate->setMaximumHeight(scaleAndRotateButton->maximumHeight());
        this->spaceControls.btnScaleAndRotate->setMaximumSize(scaleAndRotateButton->maximumSize());
        this->spaceControls.btnScaleAndRotate->setMaximumWidth(scaleAndRotateButton->maximumWidth());
        this->spaceControls.btnScaleAndRotate->setMinimumHeight(scaleAndRotateButton->minimumHeight());
        this->spaceControls.btnScaleAndRotate->setMinimumSize(scaleAndRotateButton->minimumSize());
        this->spaceControls.btnScaleAndRotate->setMinimumWidth(scaleAndRotateButton->minimumWidth());
        this->spaceControls.btnScaleAndRotate->setSizePolicy(scaleAndRotateButton->sizePolicy());
        this->spaceControls.btnScaleAndRotate->setStyle(scaleAndRotateButton->style());
        this->spaceControls.btnScaleAndRotate->setStyleSheet(scaleAndRotateButton->styleSheet());
        this->spaceControls.btnScaleAndRotate->setText(scaleAndRotateButton->text());
        this->spaceControls.btnScaleAndRotate->setVisible(scaleAndRotateButton->isVisible());
    }
}

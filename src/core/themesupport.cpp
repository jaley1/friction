/*
#
# Friction - https://friction.graphics
#
# Copyright (c) Ole-André Rodlie and contributors
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# See 'README.md' for more information.
#
*/

#include "themesupport.h"

#include <QFile>
#include <QIcon>
#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QToolButton>

const QString ThemeSupport::getAppIconName(const bool alt)
{
    const QString name = alt ? "application-x-graphics.friction.Friction" : "graphics.friction.Friction";
    return name;
}

const QColor ThemeSupport::getQColor(int r,
                                     int g,
                                     int b,
                                     int a)
{
    return a == 255 ? QColor(r, g, b) : QColor(r, g, b, a);
}

const QColor ThemeSupport::getThemeBaseColor(int alpha)
{
    return getQColor(214, 218, 226, alpha);
}

SkColor ThemeSupport::getThemeBaseSkColor(int alpha)
{
    return SkColorSetARGB(alpha, 214, 218, 226);
}

const QColor ThemeSupport::getThemeBaseDarkColor(int alpha)
{
    return getQColor(198, 203, 212, alpha);
}

const QColor ThemeSupport::getThemeBaseDarkerColor(int alpha)
{
    return getQColor(184, 190, 201, alpha);
}

const QColor ThemeSupport::getThemeAlternateColor(int alpha)
{
    return getQColor(228, 232, 238, alpha);
}

const QColor ThemeSupport::getThemeHighlightColor(int alpha)
{
    return getQColor(68, 114, 196, alpha);
}

const QColor ThemeSupport::getThemeHighlightDarkerColor(int alpha)
{
    return getQColor(47, 85, 151, alpha);
}

const QColor ThemeSupport::getThemeHighlightAlternativeColor(int alpha)
{
    return getQColor(143, 170, 220, alpha);
}

const QColor ThemeSupport::getThemeHighlightSelectedColor(int alpha)
{
    return getQColor(115, 155, 225, alpha);
}

SkColor ThemeSupport::getThemeHighlightSkColor(int alpha)
{
    return SkColorSetARGB(alpha, 68, 114, 196);
}

const QColor ThemeSupport::getThemeButtonBaseColor(int alpha)
{
    return getQColor(196, 202, 212, alpha);
}

const QColor ThemeSupport::getThemeButtonBorderColor(int alpha)
{
    return getQColor(152, 160, 174, alpha);
}

const QColor ThemeSupport::getThemeComboBaseColor(int alpha)
{
    return getQColor(232, 235, 241, alpha);
}

const QColor ThemeSupport::getThemeTimelineColor(int alpha)
{
    return getQColor(206, 211, 220, alpha);
}

const QColor ThemeSupport::getThemeRangeColor(int alpha)
{
    return getQColor(168, 189, 224, alpha);
}

const QColor ThemeSupport::getThemeRangeSelectedColor(int alpha)
{
    return getQColor(112, 148, 212, alpha);
}

const QColor ThemeSupport::getThemeFrameMarkerColor(int alpha)
{
    return getThemeColorOrange(alpha);
}

const QColor ThemeSupport::getThemeObjectColor(int alpha)
{
    return getQColor(0, 102, 255, alpha);
}

const QColor ThemeSupport::getThemeColorRed(int alpha)
{
    return getQColor(199, 67, 72, alpha);
}

const QColor ThemeSupport::getThemeColorBlue(int alpha)
{
    return getQColor(55, 118, 189, alpha);
}

const QColor ThemeSupport::getThemeColorYellow(int alpha)
{
    return getQColor(189, 158, 42, alpha);
}

const QColor ThemeSupport::getThemeColorPink(int alpha)
{
    return getQColor(155, 62, 194, alpha);
}

const QColor ThemeSupport::getThemeColorGreen(int alpha)
{
    return getQColor(52, 168, 104, alpha);
}

const QColor ThemeSupport::getThemeColorGreenDark(int alpha)
{
    return getQColor(175, 214, 192, alpha);
}

const QColor ThemeSupport::getThemeColorOrange(int alpha)
{
    return getQColor(235, 108, 0, alpha);
}

const QColor ThemeSupport::getThemeColorTextDisabled(int alpha)
{
    return getQColor(118, 124, 135, alpha);
}

const QPalette ThemeSupport::getDefaultPalette(const QColor &highlight)
{
    const QColor darkText(24, 26, 31);
    const QColor disabledText(118, 124, 135);
    QPalette palette;
    palette.setColor(QPalette::Window, getThemeAlternateColor());
    palette.setColor(QPalette::WindowText, darkText);
    palette.setColor(QPalette::Base, getThemeBaseColor());
    palette.setColor(QPalette::AlternateBase, getThemeAlternateColor());
    palette.setColor(QPalette::Link, QColor(36, 86, 175));
    palette.setColor(QPalette::LinkVisited, QColor(92, 58, 158));
    palette.setColor(QPalette::ToolTipText, darkText);
    palette.setColor(QPalette::ToolTipBase, QColor(245, 247, 250));
    palette.setColor(QPalette::Text, darkText);
    palette.setColor(QPalette::Button, getThemeBaseColor());
    palette.setColor(QPalette::ButtonText, darkText);
    palette.setColor(QPalette::BrightText, Qt::black);
    palette.setColor(QPalette::Highlight, highlight.isValid() ? highlight : getThemeHighlightColor());
    palette.setColor(QPalette::HighlightedText, Qt::white);
    palette.setColor(QPalette::Disabled, QPalette::Text, disabledText);
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, disabledText);
    return palette;
}

const QPalette ThemeSupport::getDarkPalette(int alpha)
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, getThemeBaseColor(alpha));
    pal.setColor(QPalette::Base, getThemeBaseColor(alpha));
    pal.setColor(QPalette::Button, getThemeBaseColor(alpha));
    return pal;
}

const QPalette ThemeSupport::getDarkerPalette(int alpha)
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, getThemeBaseDarkerColor(alpha));
    pal.setColor(QPalette::Base, getThemeBaseDarkerColor(alpha));
    pal.setColor(QPalette::Button, getThemeBaseDarkerColor(alpha));
    return pal;
}

const QPalette ThemeSupport::getNotSoDarkPalette(int alpha)
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, getThemeAlternateColor(alpha));
    pal.setColor(QPalette::Base, getThemeBaseColor(alpha));
    pal.setColor(QPalette::Button, getThemeBaseColor(alpha));
    return pal;
}

const QString ThemeSupport::getThemeStyle(int iconSize)
{
    QString css;
    QFile stylesheet(QString::fromUtf8(":/styles/friction.qss"));
    if (stylesheet.open(QIODevice::ReadOnly | QIODevice::Text)) {
        css = stylesheet.readAll();
        stylesheet.close();
    }
    const qreal iconPixelRatio = iconSize * qApp->desktop()->devicePixelRatioF();
    return css.arg(getThemeButtonBaseColor().name(),
                   getThemeButtonBorderColor().name(),
                   getThemeBaseDarkerColor().name(),
                   getThemeHighlightColor().name(),
                   getThemeBaseColor().name(),
                   getThemeAlternateColor().name(),
                   QString::number(getIconSize(iconSize).width()),
                   getThemeColorOrange().name(),
                   getThemeRangeSelectedColor().name(),
                   QString::number(getIconSize(iconSize / 2).width()),
                   QString::number(getIconSize(qRound(iconPixelRatio)).width()),
                   QString::number(getIconSize(qRound(iconPixelRatio / 2)).width()),
                   getThemeColorTextDisabled().name(),
                   QString::number(getIconSize(iconSize).width() / 4));
}

void ThemeSupport::setupTheme(const int iconSize)
{
    QIcon::setThemeSearchPaths(QStringList() << QString::fromUtf8(":/icons"));
    QIcon::setThemeName(QString::fromUtf8("hicolor"));
    qApp->setStyle(QString::fromUtf8("fusion"));
    qApp->setPalette(getDefaultPalette());
    qApp->setStyleSheet(getThemeStyle(iconSize));
}

const QList<QSize> ThemeSupport::getAvailableIconSizes()
{
    return QIcon::fromTheme("visible").availableSizes();
}

const QSize ThemeSupport::getIconSize(const int size)
{
    QSize requestedSize(size, size);
    const auto iconSizes = getAvailableIconSizes();
    bool hasIconSize = iconSizes.contains(requestedSize);
    if (hasIconSize) { return requestedSize; }
    const auto foundIconSize = findClosestIconSize(size);
    return foundIconSize;
}

bool ThemeSupport::hasIconSize(const int size)
{
    return getAvailableIconSizes().contains(QSize(size, size));
}

const QSize ThemeSupport::findClosestIconSize(int iconSize)
{
    const auto iconSizes = getAvailableIconSizes();
    return *std::min_element(iconSizes.begin(),
                             iconSizes.end(),
                             [iconSize](const QSize& a,
                                        const QSize& b) {
        return qAbs(a.width() - iconSize) < qAbs(b.width() - iconSize);
    });
}

void ThemeSupport::setToolbarButtonStyle(const QString &name,
                                         QToolBar *bar,
                                         QAction *act)
{
    if (!bar || !act || name.simplified().isEmpty()) { return; }
    if (QWidget *widget = bar->widgetForAction(act)) {
        if (QToolButton *button = qobject_cast<QToolButton*>(widget)) {
            button->setObjectName(name);
        }
    }
}

const QColor ThemeSupport::getLightDarkColor(const QColor &color,
                                             const int &factor)
{
    const float lightness = color.lightnessF();
    if (lightness < 0.5f) {
        const QColor col = color.lighter(factor);
        const float minLightness = 0.3f;
        if (col.lightnessF() < minLightness) {
            QColor hslColor = color.toHsl();
            hslColor.setHslF(hslColor.hslHueF(),
                             hslColor.hslSaturationF(),
                             minLightness,
                             hslColor.alphaF());
            return hslColor.toRgb();
        }
        return col;
    }

    const QColor col = color.darker(factor);
    const float maxLightness = 0.7f;
    if (col.lightnessF() > maxLightness) {
        QColor hslColor = color.toHsl();
        hslColor.setHslF(hslColor.hslHueF(),
                         hslColor.hslSaturationF(),
                         maxLightness,
                         hslColor.alphaF());
        return hslColor.toRgb();
    }
    return col;
}

ThemeIconProvider::ThemeIconProvider()
{
    mIcon = QIcon::fromTheme(ThemeSupport::getAppIconName(true));
}

QIcon ThemeIconProvider::icon(const QFileInfo &info) const
{
    const QString name = info.fileName().toLower();
    if (name.endsWith(".friction")) { return mIcon; }
    return QFileIconProvider::icon(info);
}

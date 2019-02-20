#ifndef QROUNDPROGRESSBAR_H
#define QROUNDPROGRESSBAR_H

#include <QWidget>

/*
 * 类名：QRoundProgressBar
 * 功能说明：进行进度条优化显示，当前包含三种环形进度条动态显示。
*/
class QRoundProgressBar : public  QWidget
{
    Q_OBJECT
public:
    explicit QRoundProgressBar(QWidget *parent = 0);

    static const int PositionLeft = 180;
    static const int PositionTop = 90;
    static const int PositionRight = 0;
    static const int PositionBottom = -90;

    /**
     * @brief Return position (in degrees) of minimum value.
     * \sa setNullPosition
     */
    double nullPosition() const { return m_nullPosition; }
    /**
     * @brief Defines position of minimum value.
     * @param position position on the circle (in degrees) of minimum value
     * \sa nullPosition
     */
    void setNullPosition(double position);

    //设置进度条样式
    enum BarStyle
    {
        //环形粗线条包含文字。
        StyleDonut,
        //饼状填充，包含文字。
        StylePie,
        //细线环形，包含文字。
        StyleLine
    };

    //设置进度条的样式
    void setBarStyle(BarStyle style);
    //获取当前进度条样式
    BarStyle barStyle() const { return m_barStyle; }

    //设置外圈笔的线条粗细
    void setOutlinePenWidth(double penWidth);
    //返回线条粗细
    double outlinePenWidth() const { return m_outlinePenWidth; }

    //设置数组的线条粗细
    void setDataPenWidth(double penWidth);
    //获取数字的线条粗细
    double dataPenWidth() const { return m_dataPenWidth; }

    /**
     * @brief Sets colors of the visible data and makes gradient brush from them.
     * Gradient colors can be set for \a Donut and \a Pie styles (see setBarStyle() function).
     *
     * *Warning*: this function will override widget's `palette()` to set dynamically created gradient brush.
     *
     * @param stopPoints List of colors (should have at least 2 values, see Qt's \a QGradientStops for more details).
     * Color value at point 0 corresponds to the minimum() value, while color value at point 1
     * corresponds to the maximum(). Other colors will be distributed accordingly to the defined ranges (see setRange()).
     */
    void setDataColors(const QGradientStops& stopPoints);

    /**
     * @brief Defines the string used to generate the current text.
     * If no format is set, no text will be shown.
     * @param format see \a QProgressBar's format description
     * \sa setDecimals
     */
    void setFormat(const QString& format);
    /**
     * @brief Sets format string to empty string. No text will be shown therefore.
     * See setFormat() for more information.
     */
    void resetFormat();
    /**
     * @brief Returns the string used to generate the current text.
     */
    QString	format() const { return m_format; }

    /**
     * @brief Sets number of decimals to show after the comma (default is 1).
     * \sa setFormat
     */
    void setDecimals(int count);
    /**
     * @brief Returns number of decimals to show after the comma (default is 1).
     * \sa setFormat, setDecimals
     */
    int decimals() const { return m_decimals; }

    //设置当前进度条的数值
    double value() const { return m_value; }
    //设置当前进度条的范围最小值
    double minimum() const { return m_min; }
    //设置当前进度条的范围最大值
    double maximum() const { return m_max; }

    float innerOuterRate() const;
    void setInnerOuterRate(float innerOuterRate);

public Q_SLOTS:
    /**
     * @brief Defines minimum und maximum of the allowed value range.
     * If the current value does not fit into the range, it will be automatically adjusted.
     * @param min minimum of the allowed value range
     * @param max maximum of the allowed value range
     */
    void setRange(double min, double max);
    /**
     * @brief Defines minimum of the allowed value range.
     * If the current value does not fit into the range, it will be automatically adjusted.
     * @param min minimum of the allowed value range
     * \sa setRange
     */
    void setMinimum(double min);
    /**
     * @brief Defines maximum of the allowed value range.
     * If the current value does not fit into the range, it will be automatically adjusted.
     * @param max maximum of the allowed value range
     * \sa setRange
     */
    void setMaximum(double max);
    /**
     * @brief Sets a value which will be shown on the widget.
     * @param val must be between minimum() and maximum()
     */
    void setValue(double val);
    /**
     * @brief Integer version of the previous slot.
     * @param val must be between minimum() and maximum()
     */
    void setValue(int val);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void drawBackground(QPainter& p, const QRectF& baseRect);
    virtual void drawBase(QPainter& p, const QRectF& baseRect, const QRectF &innerRect);
    virtual void drawValue(QPainter& p, const QRectF& baseRect, double value, double arcLength, const QRectF & innerRect
                           , double innerRadius);
    virtual void calculateInnerRect(const QRectF& baseRect, double outerRadius, QRectF& innerRect, double& innerRadius);
    virtual void drawInnerBackground(QPainter& p, const QRectF& innerRect);
    virtual void drawText(QPainter& p, const QRectF& innerRect, double innerRadius, double value);
    virtual QString valueToText(double value) const;
    virtual void valueFormatChanged();

    virtual QSize minimumSizeHint() const { return QSize(32,32); }

    virtual bool hasHeightForWidth() const { return true; }
    virtual int heightForWidth(int w) const { return w; }

    void rebuildDataBrushIfNeeded();

    double m_min, m_max;
    double m_value;
    float m_innerOuterRate;///< 内径比外径，这里m_innerOuterRate应该小于1
    double m_nullPosition;
    BarStyle m_barStyle;
    double m_outlinePenWidth, m_dataPenWidth;

    QGradientStops m_gradientData;
    bool m_rebuildBrush;

    QString m_format;
    int m_decimals;

    static const int UF_VALUE = 1;
    static const int UF_PERCENT = 2;
    static const int UF_MAX = 4;
    int m_updateFlags;
};

#endif // QROUNDPROGRESSBAR_H

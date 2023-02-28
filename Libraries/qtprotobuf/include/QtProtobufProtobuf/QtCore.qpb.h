/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#pragma once

#include <QObject>
#include <QMetaType>
#include <QList>
#include <QProtobufObject>
#include <QProtobufLazyMessagePointer>
#include <QSharedPointer>

#include <memory>
#include <unordered_map>

#include <QtQml/QQmlListProperty>
#include <QQmlListPropertyConstructor>

#include <QByteArray>
#include <QString>

namespace QtProtobuf {
class QUrl;
using QUrlRepeated = QList<QSharedPointer<QUrl>>;

}


namespace QtProtobuf {
class QChar;
using QCharRepeated = QList<QSharedPointer<QChar>>;

}


namespace QtProtobuf {
class QUuid;
using QUuidRepeated = QList<QSharedPointer<QUuid>>;

}


namespace QtProtobuf {
class QTime;
using QTimeRepeated = QList<QSharedPointer<QTime>>;

}


namespace QtProtobuf {
class QDate;
using QDateRepeated = QList<QSharedPointer<QDate>>;

}


namespace QtProtobuf {
class QDateTime;
using QDateTimeRepeated = QList<QSharedPointer<QDateTime>>;

}


namespace QtProtobuf {
class QSize;
using QSizeRepeated = QList<QSharedPointer<QSize>>;

}


namespace QtProtobuf {
class QSizeF;
using QSizeFRepeated = QList<QSharedPointer<QSizeF>>;

}


namespace QtProtobuf {
class QPoint;
using QPointRepeated = QList<QSharedPointer<QPoint>>;

}


namespace QtProtobuf {
class QPointF;
using QPointFRepeated = QList<QSharedPointer<QPointF>>;

}


namespace QtProtobuf {
class QRect;
using QRectRepeated = QList<QSharedPointer<QRect>>;

}


namespace QtProtobuf {
class QRectF;
using QRectFRepeated = QList<QSharedPointer<QRectF>>;

}


namespace QtProtobuf {
class QPolygon;
using QPolygonRepeated = QList<QSharedPointer<QPolygon>>;

}


namespace QtProtobuf {
class QPolygonF;
using QPolygonFRepeated = QList<QSharedPointer<QPolygonF>>;

}


namespace QtProtobuf {
namespace QUrl_QtProtobufNested {
}

class QUrl : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QUrl)
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged SCRIPTABLE true)

public:
    QUrl(QObject *parent = nullptr);
    QUrl(const QString &url,QObject *parent = nullptr);
    virtual ~QUrl();
    QUrl(const QUrl &other);
    QUrl &operator =(const QUrl &other);
    QUrl(QUrl &&other);
    QUrl &operator =(QUrl &&other);
    bool operator ==(const QUrl &other) const;
    bool operator !=(const QUrl &other) const;

    QString url() const {
        return m_url;
    }

    void setUrl(const QString &url);
    static void registerTypes();

signals:
    void urlChanged();

private:

private:
    QString m_url;
};

using QUrlRepeated = QList<QSharedPointer<QUrl>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QUrl)
Q_DECLARE_METATYPE(QtProtobuf::QUrlRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QUrl>)

namespace QtProtobuf {
namespace QChar_QtProtobufNested {
}

class QChar : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QChar)
    Q_PROPERTY(QByteArray character READ character WRITE setCharacter NOTIFY characterChanged SCRIPTABLE true)

public:
    QChar(QObject *parent = nullptr);
    QChar(const QByteArray &character,QObject *parent = nullptr);
    virtual ~QChar();
    QChar(const QChar &other);
    QChar &operator =(const QChar &other);
    QChar(QChar &&other);
    QChar &operator =(QChar &&other);
    bool operator ==(const QChar &other) const;
    bool operator !=(const QChar &other) const;

    QByteArray character() const {
        return m_character;
    }

    void setCharacter(const QByteArray &character);
    static void registerTypes();

signals:
    void characterChanged();

private:

private:
    QByteArray m_character;
};

using QCharRepeated = QList<QSharedPointer<QChar>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QChar)
Q_DECLARE_METATYPE(QtProtobuf::QCharRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QChar>)

namespace QtProtobuf {
namespace QUuid_QtProtobufNested {
}

class QUuid : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QUuid)
    Q_PROPERTY(QString uuid READ uuid WRITE setUuid NOTIFY uuidChanged SCRIPTABLE true)

public:
    QUuid(QObject *parent = nullptr);
    QUuid(const QString &uuid,QObject *parent = nullptr);
    virtual ~QUuid();
    QUuid(const QUuid &other);
    QUuid &operator =(const QUuid &other);
    QUuid(QUuid &&other);
    QUuid &operator =(QUuid &&other);
    bool operator ==(const QUuid &other) const;
    bool operator !=(const QUuid &other) const;

    QString uuid() const {
        return m_uuid;
    }

    void setUuid(const QString &uuid);
    static void registerTypes();

signals:
    void uuidChanged();

private:

private:
    QString m_uuid;
};

using QUuidRepeated = QList<QSharedPointer<QUuid>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QUuid)
Q_DECLARE_METATYPE(QtProtobuf::QUuidRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QUuid>)

namespace QtProtobuf {
namespace QTime_QtProtobufNested {
}

class QTime : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QTime)
    Q_PROPERTY(QtProtobuf::sint32 msec READ msec WRITE setMsec NOTIFY msecChanged SCRIPTABLE true)

public:
    QTime(QObject *parent = nullptr);
    QTime(QtProtobuf::sint32 msec,QObject *parent = nullptr);
    virtual ~QTime();
    QTime(const QTime &other);
    QTime &operator =(const QTime &other);
    QTime(QTime &&other);
    QTime &operator =(QTime &&other);
    bool operator ==(const QTime &other) const;
    bool operator !=(const QTime &other) const;

    QtProtobuf::sint32 msec() const {
        return m_msec;
    }

    void setMsec(const QtProtobuf::sint32 &msec) {
        if (m_msec != msec) {
            m_msec = msec;
            msecChanged();
        }
    }

    static void registerTypes();

signals:
    void msecChanged();

private:

private:
    QtProtobuf::sint32 m_msec;
};

using QTimeRepeated = QList<QSharedPointer<QTime>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QTime)
Q_DECLARE_METATYPE(QtProtobuf::QTimeRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QTime>)

namespace QtProtobuf {
namespace QDate_QtProtobufNested {
}

class QDate : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QDate)
    Q_PROPERTY(QtProtobuf::sint32 year READ year WRITE setYear NOTIFY yearChanged SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::sint32 month READ month WRITE setMonth NOTIFY monthChanged SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::sint32 day READ day WRITE setDay NOTIFY dayChanged SCRIPTABLE true)

public:
    QDate(QObject *parent = nullptr);
    QDate(QtProtobuf::sint32 year,QObject *parent = nullptr);
    QDate(QtProtobuf::sint32 year,QtProtobuf::sint32 month,QObject *parent = nullptr);
    QDate(QtProtobuf::sint32 year,QtProtobuf::sint32 month,QtProtobuf::sint32 day,QObject *parent = nullptr);
    virtual ~QDate();
    QDate(const QDate &other);
    QDate &operator =(const QDate &other);
    QDate(QDate &&other);
    QDate &operator =(QDate &&other);
    bool operator ==(const QDate &other) const;
    bool operator !=(const QDate &other) const;

    QtProtobuf::sint32 year() const {
        return m_year;
    }


    QtProtobuf::sint32 month() const {
        return m_month;
    }


    QtProtobuf::sint32 day() const {
        return m_day;
    }

    void setYear(const QtProtobuf::sint32 &year) {
        if (m_year != year) {
            m_year = year;
            yearChanged();
        }
    }

    void setMonth(const QtProtobuf::sint32 &month) {
        if (m_month != month) {
            m_month = month;
            monthChanged();
        }
    }

    void setDay(const QtProtobuf::sint32 &day) {
        if (m_day != day) {
            m_day = day;
            dayChanged();
        }
    }

    static void registerTypes();

signals:
    void yearChanged();
    void monthChanged();
    void dayChanged();

private:

private:
    QtProtobuf::sint32 m_year;
    QtProtobuf::sint32 m_month;
    QtProtobuf::sint32 m_day;
};

using QDateRepeated = QList<QSharedPointer<QDate>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QDate)
Q_DECLARE_METATYPE(QtProtobuf::QDateRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QDate>)

namespace QtProtobuf {
namespace QDateTime_QtProtobufNested {
}

class QDateTime : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QDateTime)
    Q_PROPERTY(QtProtobuf::QDate *date READ date_p WRITE setDate_p NOTIFY dateChanged)
    Q_PROPERTY(QtProtobuf::QTime *time READ time_p WRITE setTime_p NOTIFY timeChanged)

public:
    QDateTime(QObject *parent = nullptr);
    QDateTime(const QDate &date,QObject *parent = nullptr);
    QDateTime(const QDate &date,const QTime &time,QObject *parent = nullptr);
    virtual ~QDateTime();
    QDateTime(const QDateTime &other);
    QDateTime &operator =(const QDateTime &other);
    QDateTime(QDateTime &&other);
    QDateTime &operator =(QDateTime &&other);
    bool operator ==(const QDateTime &other) const;
    bool operator !=(const QDateTime &other) const;

    const QDate &date() const;

    const QTime &time() const;
    void setDate(const QDate &date);
    void setTime(const QTime &time);
    static void registerTypes();

signals:
    void dateChanged();
    void timeChanged();

private:
    QDate *date_p() const;
    QTime *time_p() const;
    void setDate_p(QDate *date);
    void setTime_p(QTime *time);

private:
    QProtobufLazyMessagePointer<QDate> m_date;
    QProtobufLazyMessagePointer<QTime> m_time;
};

using QDateTimeRepeated = QList<QSharedPointer<QDateTime>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QDateTime)
Q_DECLARE_METATYPE(QtProtobuf::QDateTimeRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QDateTime>)

namespace QtProtobuf {
namespace QSize_QtProtobufNested {
}

class QSize : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QSize)
    Q_PROPERTY(QtProtobuf::sint32 width READ width WRITE setWidth NOTIFY widthChanged SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::sint32 height READ height WRITE setHeight NOTIFY heightChanged SCRIPTABLE true)

public:
    QSize(QObject *parent = nullptr);
    QSize(QtProtobuf::sint32 width,QObject *parent = nullptr);
    QSize(QtProtobuf::sint32 width,QtProtobuf::sint32 height,QObject *parent = nullptr);
    virtual ~QSize();
    QSize(const QSize &other);
    QSize &operator =(const QSize &other);
    QSize(QSize &&other);
    QSize &operator =(QSize &&other);
    bool operator ==(const QSize &other) const;
    bool operator !=(const QSize &other) const;

    QtProtobuf::sint32 width() const {
        return m_width;
    }


    QtProtobuf::sint32 height() const {
        return m_height;
    }

    void setWidth(const QtProtobuf::sint32 &width) {
        if (m_width != width) {
            m_width = width;
            widthChanged();
        }
    }

    void setHeight(const QtProtobuf::sint32 &height) {
        if (m_height != height) {
            m_height = height;
            heightChanged();
        }
    }

    static void registerTypes();

signals:
    void widthChanged();
    void heightChanged();

private:

private:
    QtProtobuf::sint32 m_width;
    QtProtobuf::sint32 m_height;
};

using QSizeRepeated = QList<QSharedPointer<QSize>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QSize)
Q_DECLARE_METATYPE(QtProtobuf::QSizeRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QSize>)

namespace QtProtobuf {
namespace QSizeF_QtProtobufNested {
}

class QSizeF : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QSizeF)
    Q_PROPERTY(double width READ width WRITE setWidth NOTIFY widthChanged SCRIPTABLE true)
    Q_PROPERTY(double height READ height WRITE setHeight NOTIFY heightChanged SCRIPTABLE true)

public:
    QSizeF(QObject *parent = nullptr);
    QSizeF(double width,QObject *parent = nullptr);
    QSizeF(double width,double height,QObject *parent = nullptr);
    virtual ~QSizeF();
    QSizeF(const QSizeF &other);
    QSizeF &operator =(const QSizeF &other);
    QSizeF(QSizeF &&other);
    QSizeF &operator =(QSizeF &&other);
    bool operator ==(const QSizeF &other) const;
    bool operator !=(const QSizeF &other) const;

    double width() const {
        return m_width;
    }


    double height() const {
        return m_height;
    }

    void setWidth(const double &width) {
        if (m_width != width) {
            m_width = width;
            widthChanged();
        }
    }

    void setHeight(const double &height) {
        if (m_height != height) {
            m_height = height;
            heightChanged();
        }
    }

    static void registerTypes();

signals:
    void widthChanged();
    void heightChanged();

private:

private:
    double m_width;
    double m_height;
};

using QSizeFRepeated = QList<QSharedPointer<QSizeF>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QSizeF)
Q_DECLARE_METATYPE(QtProtobuf::QSizeFRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QSizeF>)

namespace QtProtobuf {
namespace QPoint_QtProtobufNested {
}

class QPoint : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QPoint)
    Q_PROPERTY(QtProtobuf::sint32 x READ x WRITE setX NOTIFY xChanged SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::sint32 y READ y WRITE setY NOTIFY yChanged SCRIPTABLE true)

public:
    QPoint(QObject *parent = nullptr);
    QPoint(QtProtobuf::sint32 x,QObject *parent = nullptr);
    QPoint(QtProtobuf::sint32 x,QtProtobuf::sint32 y,QObject *parent = nullptr);
    virtual ~QPoint();
    QPoint(const QPoint &other);
    QPoint &operator =(const QPoint &other);
    QPoint(QPoint &&other);
    QPoint &operator =(QPoint &&other);
    bool operator ==(const QPoint &other) const;
    bool operator !=(const QPoint &other) const;

    QtProtobuf::sint32 x() const {
        return m_x;
    }


    QtProtobuf::sint32 y() const {
        return m_y;
    }

    void setX(const QtProtobuf::sint32 &x) {
        if (m_x != x) {
            m_x = x;
            xChanged();
        }
    }

    void setY(const QtProtobuf::sint32 &y) {
        if (m_y != y) {
            m_y = y;
            yChanged();
        }
    }

    static void registerTypes();

signals:
    void xChanged();
    void yChanged();

private:

private:
    QtProtobuf::sint32 m_x;
    QtProtobuf::sint32 m_y;
};

using QPointRepeated = QList<QSharedPointer<QPoint>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QPoint)
Q_DECLARE_METATYPE(QtProtobuf::QPointRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QPoint>)

namespace QtProtobuf {
namespace QPointF_QtProtobufNested {
}

class QPointF : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QPointF)
    Q_PROPERTY(double x READ x WRITE setX NOTIFY xChanged SCRIPTABLE true)
    Q_PROPERTY(double y READ y WRITE setY NOTIFY yChanged SCRIPTABLE true)

public:
    QPointF(QObject *parent = nullptr);
    QPointF(double x,QObject *parent = nullptr);
    QPointF(double x,double y,QObject *parent = nullptr);
    virtual ~QPointF();
    QPointF(const QPointF &other);
    QPointF &operator =(const QPointF &other);
    QPointF(QPointF &&other);
    QPointF &operator =(QPointF &&other);
    bool operator ==(const QPointF &other) const;
    bool operator !=(const QPointF &other) const;

    double x() const {
        return m_x;
    }


    double y() const {
        return m_y;
    }

    void setX(const double &x) {
        if (m_x != x) {
            m_x = x;
            xChanged();
        }
    }

    void setY(const double &y) {
        if (m_y != y) {
            m_y = y;
            yChanged();
        }
    }

    static void registerTypes();

signals:
    void xChanged();
    void yChanged();

private:

private:
    double m_x;
    double m_y;
};

using QPointFRepeated = QList<QSharedPointer<QPointF>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QPointF)
Q_DECLARE_METATYPE(QtProtobuf::QPointFRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QPointF>)

namespace QtProtobuf {
namespace QRect_QtProtobufNested {
}

class QRect : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QRect)
    Q_PROPERTY(QtProtobuf::QPoint *position READ position_p WRITE setPosition_p NOTIFY positionChanged)
    Q_PROPERTY(QtProtobuf::QSize *size READ size_p WRITE setSize_p NOTIFY sizeChanged)

public:
    QRect(QObject *parent = nullptr);
    QRect(const QPoint &position,QObject *parent = nullptr);
    QRect(const QPoint &position,const QSize &size,QObject *parent = nullptr);
    virtual ~QRect();
    QRect(const QRect &other);
    QRect &operator =(const QRect &other);
    QRect(QRect &&other);
    QRect &operator =(QRect &&other);
    bool operator ==(const QRect &other) const;
    bool operator !=(const QRect &other) const;

    const QPoint &position() const;

    const QSize &size() const;
    void setPosition(const QPoint &position);
    void setSize(const QSize &size);
    static void registerTypes();

signals:
    void positionChanged();
    void sizeChanged();

private:
    QPoint *position_p() const;
    QSize *size_p() const;
    void setPosition_p(QPoint *position);
    void setSize_p(QSize *size);

private:
    QProtobufLazyMessagePointer<QPoint> m_position;
    QProtobufLazyMessagePointer<QSize> m_size;
};

using QRectRepeated = QList<QSharedPointer<QRect>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QRect)
Q_DECLARE_METATYPE(QtProtobuf::QRectRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QRect>)

namespace QtProtobuf {
namespace QRectF_QtProtobufNested {
}

class QRectF : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QRectF)
    Q_PROPERTY(QtProtobuf::QPointF *position READ position_p WRITE setPosition_p NOTIFY positionChanged)
    Q_PROPERTY(QtProtobuf::QSizeF *size READ size_p WRITE setSize_p NOTIFY sizeChanged)

public:
    QRectF(QObject *parent = nullptr);
    QRectF(const QPointF &position,QObject *parent = nullptr);
    QRectF(const QPointF &position,const QSizeF &size,QObject *parent = nullptr);
    virtual ~QRectF();
    QRectF(const QRectF &other);
    QRectF &operator =(const QRectF &other);
    QRectF(QRectF &&other);
    QRectF &operator =(QRectF &&other);
    bool operator ==(const QRectF &other) const;
    bool operator !=(const QRectF &other) const;

    const QPointF &position() const;

    const QSizeF &size() const;
    void setPosition(const QPointF &position);
    void setSize(const QSizeF &size);
    static void registerTypes();

signals:
    void positionChanged();
    void sizeChanged();

private:
    QPointF *position_p() const;
    QSizeF *size_p() const;
    void setPosition_p(QPointF *position);
    void setSize_p(QSizeF *size);

private:
    QProtobufLazyMessagePointer<QPointF> m_position;
    QProtobufLazyMessagePointer<QSizeF> m_size;
};

using QRectFRepeated = QList<QSharedPointer<QRectF>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QRectF)
Q_DECLARE_METATYPE(QtProtobuf::QRectFRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QRectF>)

namespace QtProtobuf {
namespace QPolygon_QtProtobufNested {
}

class QPolygon : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QPolygon)
    Q_PROPERTY(QtProtobuf::QPointRepeated pointsData READ points WRITE setPoints NOTIFY pointsChanged SCRIPTABLE true)
    Q_PROPERTY(QQmlListProperty<QtProtobuf::QPoint> points READ points_l NOTIFY pointsChanged)

public:
    QPolygon(QObject *parent = nullptr);
    QPolygon(const QPointRepeated &points,QObject *parent = nullptr);
    virtual ~QPolygon();
    QPolygon(const QPolygon &other);
    QPolygon &operator =(const QPolygon &other);
    QPolygon(QPolygon &&other);
    QPolygon &operator =(QPolygon &&other);
    bool operator ==(const QPolygon &other) const;
    bool operator !=(const QPolygon &other) const;

    QPointRepeated points() const {
        return m_points;
    }

    QPointRepeated &points() {
        return m_points;
    }

    QQmlListProperty<QPoint> points_l();
    void setPoints(const QPointRepeated &points);
    static void registerTypes();

signals:
    void pointsChanged();

private:

private:
    QPointRepeated m_points;
};

using QPolygonRepeated = QList<QSharedPointer<QPolygon>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QPolygon)
Q_DECLARE_METATYPE(QtProtobuf::QPolygonRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QPolygon>)

namespace QtProtobuf {
namespace QPolygonF_QtProtobufNested {
}

class QPolygonF : public QObject
{
    Q_OBJECT
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(QPolygonF)
    Q_PROPERTY(QtProtobuf::QPointFRepeated pointsData READ points WRITE setPoints NOTIFY pointsChanged SCRIPTABLE true)
    Q_PROPERTY(QQmlListProperty<QtProtobuf::QPointF> points READ points_l NOTIFY pointsChanged)

public:
    QPolygonF(QObject *parent = nullptr);
    QPolygonF(const QPointFRepeated &points,QObject *parent = nullptr);
    virtual ~QPolygonF();
    QPolygonF(const QPolygonF &other);
    QPolygonF &operator =(const QPolygonF &other);
    QPolygonF(QPolygonF &&other);
    QPolygonF &operator =(QPolygonF &&other);
    bool operator ==(const QPolygonF &other) const;
    bool operator !=(const QPolygonF &other) const;

    QPointFRepeated points() const {
        return m_points;
    }

    QPointFRepeated &points() {
        return m_points;
    }

    QQmlListProperty<QPointF> points_l();
    void setPoints(const QPointFRepeated &points);
    static void registerTypes();

signals:
    void pointsChanged();

private:

private:
    QPointFRepeated m_points;
};

using QPolygonFRepeated = QList<QSharedPointer<QPolygonF>>;

}

Q_DECLARE_METATYPE(QtProtobuf::QPolygonF)
Q_DECLARE_METATYPE(QtProtobuf::QPolygonFRepeated)
Q_DECLARE_METATYPE(QQmlListProperty<QtProtobuf::QPolygonF>)
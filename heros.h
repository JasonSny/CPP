#ifndef Heros_H
#define Heros_H

#include <QString>
#include <QDebug>

class Heros
{
public:
    static QVector<Heros *> created;

    QString type() const;
    void setType(const QString &type);

    QString name() const;
    void setName(const QString &name);

    QString resistance() const;
    void setResistance(const QString &resistance);

    void Info();
    virtual void Resistance() =0;

    void receiveDmgs(int dmg_pts);


    int resistancePts() const;
    void setResistancePts(int resistancePts);

    int getPdv() const;
    void setPdv(int value);

    ~Heros();

private:
    QString m_type;
    QString m_name;
    QString m_resistance;
    int m_resistancePts;
    int pdv = 10;
};

template <typename T>
class THeros : public Heros
{
public:
    static Heros *create(){
        qDebug() << "Heroes built";
        return new T;
    };
    virtual void Resistance(){
        qDebug() << "Resistance heros";
    }

};

class Warrior : public THeros<Warrior> {
public:
    void Resistance() {
        setResistance("Physique");
        setResistancePts(4);
    }
};

class Wizzard : public THeros<Wizzard> {
public:
    void Resistance() {
        setResistance("Magique");
        setResistancePts(4);
    }

};

class Rogue : public THeros<Rogue> {
public:
    void Resistance() {
        setResistance("Piege");
        setResistancePts(4);
    }

};

#endif // Heros_H

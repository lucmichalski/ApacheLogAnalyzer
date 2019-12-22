/*************************************************************************
					    Date - Représente une date
							 -------------------
	début                : 11/12/2019
	copyright            : (C) 2019 par :
							- Milène DAUGAN
							- Loïc DUBOIS-TERMOZ
	e-mail               :
							- milene.daugan@insa-lyon.fr
							- loic.dubois-termoz@insa-lyon.fr
*************************************************************************/
#ifndef APACHELOGANALYZER_DATE_H
#define APACHELOGANALYZER_DATE_H

/**
 * Classe comportement les informations sur la date enregistrée.
 */
class Date {
public:
    /**
     * Permet de consulter la description du contenu de l'objet manipulé en affichant
     * sur la sortie standard une chaîne de caractères comportant les valeurs de chaque attribut.
     *
     * @return Le fichier de sortie en paramètre
     */
    friend std::ostream &operator<<(std::ostream &os, const Date &date);

    /**
     * Vérifie si les deux dates sont égales pour chaque attribut de chaque instance.
     *
     * @param date La date à comparer avec la date manipulée
     * @return "true" si les deux dates sont égales, "false" sinon
     */
    bool operator==(const Date &date) const {
        return (year == date.year) && (month == date.month) && (day == date.day) && (hour == date.hour)
            && (minute == date.minute) && (second == date.second) && (timeSlot == date.timeSlot);
    }

    /**
     * @return L'année de la date
     */
    int GetYear() const { return year; }

    /**
     * @return Le mois de la date (entre 1 et 12)
     */
    int GetMonth() const { return month; }

    /**
     * @return Le jour de la date (entre 1 et 31)
     */
    int GetDay() const { return day; }

    /**
     * @return L'heure de la date (entre 0 et 23)
     */
    int GetHour() const { return hour; }

    /**
     * @return La minute de la date (entre 0 et 59)
     */
    int GetMinute() const { return minute; }

    /**
     * @return La seconde de la date (entre 0 et 59)
     */
    int GetSecond() const { return second; }

    /**
     * @return Le créneaux horaire de la date
     */
    int GetTimeSlot() const { return timeSlot; }

    /**
     * Constructeur par défaut.
     */
    Date() = default;

    /**
     * Constructeur de la date.
     *
     * @param _year L'année de la date
     * @param _month Le mois de la date (entre 1 et 12)
     * @param _day L'heure de la date (entre 0 et 23)
     * @param _hour La minute de la date (entre 0 et 59)
     * @param _minute La minute de la date (entre 0 et 59)
     * @param _second La seconde de la date (entre 0 et 59)
     * @param _timeSlot Le créneaux horaire de la date
     */
    Date(int _year, int _month, int _day, int _hour, int _minute, int _second, int _timeSlot) :
        year(_year), month(_month), day(_day), minute(_minute), second(_second), timeSlot(_timeSlot) {}

protected:
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    int timeSlot = 0;
};

inline std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "Date{year=" << date.year
        << ", month=" << date.month
        << ", day=" << date.day
        << ", hour=" << date.hour
        << ", minute=" << date.minute
        << ", second=" << date.second
        << ", timeslot=" << date.timeSlot
        << "}";
    return os;
}

#endif //APACHELOGANALYZER_DATE_H

#ifndef GCS_H
#define GCS_H

class GCS
{
public:
    GCS();
    double latitude() const;
    void setLatitude(double newLatitude);

    double longitude() const;
    void setLongitude(double newLongitude);

private:
    double m_latitude;
    double m_longitude;


};

#endif // GCS_H

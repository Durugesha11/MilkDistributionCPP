#include "gcs.h"

GCS::GCS() {}

double GCS::latitude() const
{
    return m_latitude;
}

void GCS::setLatitude(double newLatitude)
{
    m_latitude = newLatitude;
}

double GCS::longitude() const
{
    return m_longitude;
}

void GCS::setLongitude(double newLongitude)
{
    m_longitude = newLongitude;
}

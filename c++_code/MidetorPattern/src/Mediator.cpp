#include "Mediator.h"
#include "Country.h"
void Mediator::addCountry(Country *country)
{
    m_countryMap.insert(make_pair(country->getName(), country));
}
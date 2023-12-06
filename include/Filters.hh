#ifndef FILTERS_HH
#define FILTERS_HH

// ROOT headers
#include "TObject.h"

#include "Particle.hh"
#include "Event.hh"

// Standard headers
#include "iostream"
#include <functional>

using namespace std;

class Filters: public TObject
{
    public: 
        using FilterFunction = std::function<bool(Event&)>;    // create a holder for filter functions

        //! constructor
		Filters(std::vector<std::string>& _filtersToBeUsed);  

		//! desctructor
		~Filters();

        // void add_filters(const std::vector<FilterFunction>& _filters);
        
        bool event_has_two_negative_particles        (Event& _event);
        bool event_has_two_particles                 (Event& _event);
        bool event_has_particles                     (Event& _event);
        bool event_has_sum_energy_above              (Event& _event, double _minEnergy);
        bool event_has_sum_energy_below              (Event& _event, double _maxEnergy);    
        bool event_has_two_tracks                    (Event& _event);                       //this is equivalend to event_has_two_particles
        bool event_has_two_foil_vertices             (Event& _event);
        bool event_has_two_calo_hits                 (Event& _event);
        bool event_has_two_associated_calo_hits      (Event& _event);

        void set_min_sum_energy(double _minSumEnergy);
        void set_max_sum_energy(double _maxSumEnergy);

        double get_min_sum_energy();
        double get_max_sum_energy();

        bool event_passed_filters(Event& _event);

    private:
        // std::vector<FilterFunction> filters;

        bool useEventHasTwoNegativeParticles = false; 
        bool useEventHasSumEnergyAbove = false; 

        double minSumEnergy;
        double maxSumEnergy;
    
	ClassDef(Filters,1);
};

#endif // FILTERS_HH
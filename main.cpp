 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct Train
{
    //number of train cars
    int numTrainCars = 5;
    //number of seats
    int numSeats = 100;
    //the amount of electrcity used per week
    float electricityUsedPerWeek = 28000.f; 
    //number of miles traveled per day
    double numMilesTravelPerDay = 268.6;
    //ticket price
    double ticketPrice = 12;

    //3 things it can do:
    //take customer to destination
    void takeCustomerToDestination(bool isCustomerDestination);

    //check ticket
    void checkTicket(bool customerBoughtTicket);

    //pickup customers at station
    bool pickupCustomer(int amountCustomerAtStop); //returns true if there is any customers to pick up
};

struct Restaurant 
{
    //number of food items
    int numFoodItems = 15;
    //number of plates
    int numPlates = 200;
    //number of chairs
    int numChairs = 50;
    //number of tables
    int numTables = 15;
    //operating hours
    double operatingHours = 9.5;

    //3 things it can do:
    //feed customer
    void feedCustomer(bool customerIsHungry, int numCustomerAtTable, bool foodOrderedAvailable);

    //serve customer
    void serveCustomer(bool customerOrderedFood);

    //reserve seats for customer
    bool reserveSeatsCustomer(int numCustomer, bool fullyBooked); //returns true is the amount of customers wanting to book can book
};

struct Airport
{
    //number of planes
    int numPlanes = 30;
    //lenght of runway in m
    int lengthRunwayM = 2800;
    //number of gates
    int numGates = 20;
    //secirity line wait time
    int securityLineWaitTime = 22;
    //number of private jets
    int numPrivateJets = 2;
    
    struct CommercialPlane
    {
        bool isAPrivateJet = false;
        int numEngines = 4;
        std::string manufacturer = "Boeing";
        std::string model = "747";
        int numSeats = 416;

        void checkFlight(float milesTraveled, int yearsOld, bool warningLightOn);
        void refillInventory(int lenghtOfNextFlight, int stockLevelInPlane);
        void leaveOnTime(bool allPassangersAtGate, double timeArrived, double timeForDeparture);
    };

    //3 things it can do:    
    //board customer on a plane
    void boardCustomerOnPlane(CommercialPlane atGate);

    //move luggage
    void moveLuggage(bool conveyorBeltOn, double weightOfLuggage);

    //delay flight
    void delayFlight(double amountDelayed);
};

struct Gym 
{
    //number of staff
    int numStaff = 8;
    //number of weights
    int numWeights = 120;
    //number of lockers
    int numLockers = 60;
    //amount of cardio machines
    int numCardioMachines = 10;
    //brand of equipment
    std::string brandEquipment = "Technogym";
    //3 things it can do:
   
    struct BenchPress 
    {
        int weightBar = 20;
        int weightPutOn = 120;
        bool weightLocksUsed = false;
        bool spotterInPlace = false;
        std::string person = "bodyBuilder";

        void performRepetitions(float weightOfPerson = 90, bool firstExercis = true);
        void getInjured(std::string injuryArea, bool rippedMusle = false);
        void dropBar(int experienceLevel = 8, int gripStrength = 10, bool areTired = false);
    };

    //3 things it can do:
    //make customer loose weight
    void makeCustomerLooseWeight(BenchPress customer);

    //make customer build muscles
    void makeCustomerBuildMuscles(BenchPress customer);

    //run exercis classes
    void runExercisClasses (std::string typeOfClass, int lengthOfClass, int numCustomerSignedUpForClass);
};

struct InnerPot
{
    //height in cm
    double heightCm = 15.8;
    //width in cm
    double widthCm = 23.8;
    //circumference in cm
    double circumferenceCm = 74.8;
    //thickness in mm
    int thicknessMm = 6;
    //volume in liters
    int volumeLiters = 6;

    //3 things it can do:
    //be taken out of outer pot
    void takenOutOfInnerPot(int timeLeftBeforeFoodDone, bool lidOn);

    //hold food
    void holdFood(bool potEmpty);

    //show max volume of food able to be cooked at once
    void showMaxVolumeFoodAbleToBeCookedAtOnce(bool potOverFilled);
};

struct OuterPot
{
    //volume of condensation collector in ml
    float volumeCondensationCollectorMl = 50.f;
    //amount of heat produced in celsius
    double amountHeatCelsius = 118;
    //amount of power consumed
    float amountPowerConumed = 4.f;
    //number of handles
    int numHandles = 2;
    //number of feet
    int numFeet = 4;

    //3 things it can do:
    //keep heat in
    void keepHeat(bool keepWarmButtonOn);

    //get rid of excess condesation
    void getRidExcessCondensation(int amountOfExcessCondensation, bool condensationCollectorFull);

    //create pressure
    void createPressure(bool lidSealed, bool valveClosed, InnerPot amountLiquid, int temperture);
};

struct ControlPanel
{
    //number of buttons
    int numButtons = 18;
    //number of display pixels
    int numDisplyPixels = 120;
    //brightness of display
    double brighnessDisplay = 100;
    //number of lights
    int numLights = 19;
    //number of settings
    int numSettings = 23;

    //3 things it can do:
    //set temperture
    void setTemperture(bool highClicked, bool mediumClicked, bool lowClicked);

    //start a cooking program
    void startCookingProgram(std::string cookingProgram, bool electricityConnected);

    //show cooking time
    float showCookingTime(float cookingTimePassed); //returns how long is left when you check it
};

struct Lid
{
    //circumference in cm
    int circumferenceCm = 80;
    //thickness of sealing ring in mm
    float thicknessSealingRingMm = 5.25f;
    //number of lid fins
    int numLidFins = 2;
    //height of lid handle in cm
    int heightLidHandleCm = 2;
    //number of holes in exhaust valve
    int numholesExhaustValve = 3;

    //3 things it can do:
    //seal Instant Pot
    void sealInstantPot(bool lockEnganged, bool steamValveClosed);

    //release steam
    void releaseSteam(bool steamValveOpen);

    //twist on Instant Pot
    void twistOnInstanPot(bool noBlockage);
};

struct Trivet
{
    
    //height of feet in cm
    double heightFeetCm = 1.4;
    //length of arms in cm
    double lengthArmsCm = 10.5;
    //length between grills cm
    double lengthBetweenGrillsCm = 3;
    //number of grills longitudinal
    int numgrillsLongitudinal = 1;
    //number of grills latera
    int numGrillsLateral = 4;

    //3 things it can do:
    //hold external steaming rack
    void holdExternalSteamingRack(bool amrsInPlace);

    //lift food out
    void liftFoodOut(int numFoodItems, int weightOfFoodItems, int sizeOfFoodItems);

    //fold together
    void foldTogether(bool beenWashed);
};

struct InstantPot
{
    //Inner Pot
    InnerPot innerPot;
    //Outer Pot
    OuterPot outerPot;
    //Control Panel
    ControlPanel controlPanel;
    //Lid
    Lid lid;
    //Trivet
    Trivet trivet;

    //3 things it can do:
    //make yoghurt
    void makeYoghurt(int amountYoghurt);

    //slow cook food
    void slowCookFood(int timeUntilDinner);

    //pressure cook food
    void pressureCookFood(InnerPot filledToMin);
};





int main()
{
    std::cout << "good to go!" << std::endl;
}

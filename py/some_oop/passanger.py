import unittest

class Passenger:
    def __init__(self, name: str, from_: str, to: str):
        self.name = name
        self.from_ = from_
        self.to = to


class Luggage:
    weight_limit = 20.0
    
    def __init__(self, passenger: Passenger, weight: float):
        self.passenger = passenger
        self.__weight = weight
    
    @property
    def weight(self):
        return self.__weight
    
    @weight.setter
    def weight(self, value):
        if not isinstance(value, (float, int)):
            raise TypeError
        
        if value <= 0 or value > self.weight_limit:
            raise ValueError
        
        self.__weight = value
    
    def __str__(self):
        return f"Luggage: {str(self.weight)} kg, owner: {self.passenger.name}"
        


class Cargo:
    def __init__(self):
        self.__luggage_list = []
    
    def add(self, luggage):
        if not isinstance(luggage, Luggage):
            raise TypeError
        
        self.__luggage_list.append(luggage)
    
    def remove(self, luggage):
        if not isinstance(luggage, Luggage):
            raise TypeError
            
        if luggage not in self.__luggage_list:
            raise KeyError
        
        self.__luggage_list.remove(luggage)
    
    def get_all(self):
        return self.__luggage_list
    
    def get_by_passenger(self, passanger):
        if not isinstance(passanger, Passenger):
            raise TypeError
        
        result = []
        
        for luggage in self.__luggage_list:
            if luggage.passenger == passanger:
                result.append(luggage)
        
        return result
    
    @property
    def weight(self):
        return sum([luggage.weight for luggage in self.__luggage_list])



class TestPassenger(unittest.TestCase):
    def test_passenger_initialization(self):
        passenger = Passenger(name="John", from_="New York", to="London")
        self.assertEqual(passenger.name, "John")
        self.assertEqual(passenger.from_, "New York")
        self.assertEqual(passenger.to, "London")


class TestLuggage(unittest.TestCase):
    def setUp(self):
        self.passenger = Passenger(name="Alice", from_="Paris", to="Berlin")
        Luggage.weight_limit = 30.0
        self.luggage = Luggage(passenger=self.passenger, weight=15.0)

    def test_luggage_initialization(self):
        self.assertEqual(self.luggage.passenger, self.passenger)
        self.assertEqual(self.luggage.weight, 15.0)

    def test_luggage_weight_setter_valid(self):
        self.luggage.weight = 20.0
        self.assertEqual(self.luggage.weight, 20.0)

    def test_luggage_weight_setter_invalid_type(self):
        with self.assertRaises(TypeError):
            self.luggage.weight = "not a float"

    def test_luggage_weight_setter_invalid_value(self):
        with self.assertRaises(ValueError):
            self.luggage.weight = 0.0

        with self.assertRaises(ValueError):
            self.luggage.weight = 50.0

    def test_luggage_str(self):
        self.assertEqual(str(self.luggage), "Luggage: 15.0 kg, owner: Alice")


class TestCargo(unittest.TestCase):
    def setUp(self):
        self.passenger1 = Passenger(name="Bob", from_="Madrid", to="Rome")
        self.passenger2 = Passenger(name="Charlie", from_="Tokyo", to="Seoul")
        self.luggage1 = Luggage(passenger=self.passenger1, weight=10.0)
        self.luggage2 = Luggage(passenger=self.passenger2, weight=20.0)
        self.cargo = Cargo(luggage_list=[self.luggage1, self.luggage2])

    def test_cargo_initialization(self):
        self.assertEqual(self.cargo.get_all(), [self.luggage1, self.luggage2])

    def test_add_luggage_valid(self):
        new_luggage = Luggage(passenger=self.passenger1, weight=5.0)
        self.cargo.add(new_luggage)
        self.assertIn(new_luggage, self.cargo.get_all())

    def test_add_luggage_invalid_type(self):
        with self.assertRaises(TypeError):
            self.cargo.add("not a luggage object")

    def test_remove_luggage_valid(self):
        self.cargo.remove(self.luggage1)
        self.assertNotIn(self.luggage1, self.cargo.get_all())

    def test_remove_luggage_invalid_type(self):
        with self.assertRaises(TypeError):
            self.cargo.remove("not a luggage object")

    def test_get_all(self):
        self.assertEqual(self.cargo.get_all(), [self.luggage1, self.luggage2])

    def test_get_by_passenger(self):
        result = self.cargo.get_by_passenger(self.passenger1)
        self.assertEqual(result, [self.luggage1])

    def test_get_by_passenger_invalid_type(self):
        with self.assertRaises(TypeError):
            self.cargo.get_by_passenger("not a passenger object")

    def test_total_weight(self):
        self.assertEqual(self.cargo.weight, 30.0)


if __name__ == "__main__":
    unittest.main()

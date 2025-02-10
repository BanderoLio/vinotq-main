import unittest


class Dish:
    categories = []

    def __init__(self, name: str, price: float, category: str):
        self.name = name
        self.__price = price
        self.__category = category

    @property
    def price(self):
        return self.__price

    @price.setter
    def price(self, new_price):
        if not isinstance(new_price, float):
            raise TypeError

        if new_price < 0:
            raise ValueError

        self.__price = new_price

    @property
    def category(self):
        return self.__category

    @category.setter
    def category(self, new_category):
        if new_category not in self.categories:
            raise TypeError

        self.__category = new_category

    def __str__(self):
        return f"Dish: {self.name}, price: {self.price}, category: {self.category}"


class Order:
    def __init__(self, order_list: list[Dish]):
        self._order_list = order_list

    def add_dish(self, new_dish):
        if not isinstance(new_dish, Dish):
            raise TypeError

        self._order_list.append(new_dish)

    def remove_dish(self, dish):
        if not isinstance(dish, Dish):
            raise TypeError

        self._order_list.remove(dish)

    def info(self):
        return [dish for dish in self._order_list]

    def get_by_category(self, category):
        if category not in Dish.categories:
            raise TypeError

        return [dish for dish in self._order_list if dish.category == category]

    @property
    def price(self):
        return sum([dish.price for dish in self._order_list])


class TestDish(unittest.TestCase):
    def setUp(self):
        Dish.categories = ["Starter", "Main Course", "Dessert"]
        self.dish = Dish(name="Pasta", price=12.5, category="Main Course")

    def test_dish_initialization(self):
        self.assertEqual(self.dish.name, "Pasta")
        self.assertEqual(self.dish.price, 12.5)
        self.assertEqual(self.dish.category, "Main Course")

    def test_dish_price_setter_valid(self):
        self.dish.price = 15.0
        self.assertEqual(self.dish.price, 15.0)

    def test_dish_price_setter_invalid_type(self):
        with self.assertRaises(TypeError):
            self.dish.price = "not a float"

    def test_dish_price_setter_invalid_value(self):
        with self.assertRaises(ValueError):
            self.dish.price = -5.0

    def test_dish_category_setter_valid(self):
        self.dish.category = "Dessert"
        self.assertEqual(self.dish.category, "Dessert")

    def test_dish_category_setter_invalid(self):
        with self.assertRaises(TypeError):
            self.dish.category = "Invalid Category"

    def test_dish_str(self):
        self.assertEqual(
            str(self.dish), "Dish: Pasta, price: 12.5, category: Main Course"
        )


class TestOrder(unittest.TestCase):
    def setUp(self):
        Dish.categories = ["Starter", "Main Course", "Dessert"]
        self.dish1 = Dish(name="Soup", price=5.0, category="Starter")
        self.dish2 = Dish(name="Steak", price=20.0, category="Main Course")
        self.order = Order(order_list=[self.dish1, self.dish2])

    def test_order_initialization(self):
        self.assertEqual(self.order.info(), [self.dish1, self.dish2])

    def test_add_dish_valid(self):
        new_dish = Dish(name="Cake", price=7.0, category="Dessert")
        self.order.add_dish(new_dish)
        self.assertIn(new_dish, self.order.info())

    def test_add_dish_invalid_type(self):
        with self.assertRaises(TypeError):
            self.order.add_dish("not a dish object")

    def test_remove_dish_valid(self):
        self.order.remove_dish(self.dish1)
        self.assertNotIn(self.dish1, self.order.info())

    def test_remove_dish_invalid_type(self):
        with self.assertRaises(TypeError):
            self.order.remove_dish("not a dish object")

    def test_get_by_category_valid(self):
        result = self.order.get_by_category("Starter")
        self.assertEqual(result, [self.dish1])

    def test_get_by_category_invalid(self):
        with self.assertRaises(TypeError):
            self.order.get_by_category("Invalid Category")

    def test_total_price(self):
        self.assertEqual(self.order.price, 25.0)

    def test_large_order(self):
        large_order = [Dish(name=f"Dish {i}", price=i * 1.5, category="Main Course") for i in range(1, 100)]
        for dish in large_order:
            self.order.add_dish(dish)
        self.assertEqual(len(self.order.info()), 101)  # Initial 2 dishes + 99 new ones
        self.assertAlmostEqual(self.order.price, sum(dish.price for dish in large_order) + 25.0, places=2)

    def test_combined_category_filtering(self):
        new_dishes = [
            Dish(name="Salad", price=4.0, category="Starter"),
            Dish(name="Brownie", price=6.0, category="Dessert")
        ]
        for dish in new_dishes:
            self.order.add_dish(dish)
        starters = self.order.get_by_category("Starter")
        desserts = self.order.get_by_category("Dessert")
        self.assertEqual(len(starters), 2)  # Original + new starter
        self.assertEqual(len(desserts), 1)  # New dessert
        


if __name__ == "__main__":
    unittest.main()

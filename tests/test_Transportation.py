import unittest
import TP_Algos  # our `pybind11`-based extension module

# Case 1
costs1 = [[3, 1, 7, 4], [2, 6, 5, 9], [8, 3, 3, 2]]
supply1 = [300, 400, 500]
demand1 = [250, 350, 400, 200]

#Case 2
costs2 = [[1, 2, 1, 4], [3, 3, 2, 1], [4, 2, 5, 9]]
supply2 = [30, 50, 20]
demand2 = [20, 40, 30, 10]

#Case 3
costs3 = [[19, 30, 50, 10], [70, 30, 40, 60], [40, 8, 70, 20]]
supply3 = [7, 9, 18]
demand3 = [5, 8, 7, 14]

#Case 4
costs4 = [[11, 13, 17, 14], [16, 18, 14, 10], [21, 24, 13, 10]]
supply4 = [250, 300, 400]
demand4 = [200, 225, 275, 250]


class MainTest(unittest.TestCase):
    def test_NCW(self):
        test1 = TP_Algos.NorthWestCorner(costs1, supply1, demand1)
        self.assertEqual(test1.totalCost, 4400)
        self.assertEqual(test1.allocated, [[250, 50, 0, 0], [0, 300, 100, 0], [0, 0, 300, 200]])

        test2 = TP_Algos.NorthWestCorner(costs2, supply2, demand2)
        self.assertEqual(test2.totalCost, 310)
        self.assertEqual(test2.allocated, [[20, 10, 0, 0], [0, 30, 20, 0], [0, 0, 10, 10]])

        test3 = TP_Algos.NorthWestCorner(costs3, supply3, demand3)
        self.assertEqual(test3.totalCost, 1015)
        self.assertEqual(test3.allocated, [[5, 2, 0, 0], [0, 6, 3, 0], [0, 0, 4, 14]])
        
        test4 = TP_Algos.NorthWestCorner(costs4, supply4, demand4)
        self.assertEqual(test4.totalCost, 12200)
        self.assertEqual(test4.allocated, [[200, 50, 0, 0], [0, 175, 125, 0], [0, 0, 150, 250]])
        

    def test_LCM(self):
        test1 = TP_Algos.LeastCostMethod(costs1, supply1, demand1)
        self.assertEqual(test1.totalCost, 2850)
        self.assertEqual(test1.allocated, [[0, 300, 0, 0], [250, 0, 150, 0], [0, 50, 250, 200]])

        test2 = TP_Algos.LeastCostMethod(costs2, supply2, demand2)
        self.assertEqual(test2.totalCost, 180)
        self.assertEqual(test2.allocated, [[20, 0, 10, 0], [0, 20, 20, 10], [0, 20, 0, 0]])

        test3 = TP_Algos.LeastCostMethod(costs3, supply3, demand3)
        self.assertEqual(test3.totalCost, 814)
        self.assertEqual(test3.allocated, [[0, 0, 0, 7], [2, 0, 7, 0], [3, 8, 0, 7]])
        
        test4 = TP_Algos.LeastCostMethod(costs4, supply4, demand4)
        self.assertEqual(test4.totalCost, 12825) # 815
        self.assertEqual(test4.allocated, [[200, 50, 0, 0], [0, 50, 0, 250], [0, 125, 275, 0]])
        
       
    def test_VAM(self):
        test1 = TP_Algos.VogelApproximationMethod(costs1, supply1, demand1)
        self.assertEqual(test1.totalCost, 2850)
        self.assertEqual(test1.allocated, [[0, 300, 0, 0], [250, 0, 150, 0], [0, 50, 250, 200]])

        test2 = TP_Algos.VogelApproximationMethod(costs2, supply2, demand2)
        self.assertEqual(test2.totalCost, 180)
        self.assertEqual(test2.allocated, [[20, 0, 10, 0], [0, 20, 20, 10], [0, 20, 0, 0]])
        
        test3 = TP_Algos.VogelApproximationMethod(costs3, supply3, demand3)
        self.assertEqual(test3.totalCost, 779)
        self.assertEqual(test3.allocated, [[5, 0, 0, 2], [0, 0, 7, 2], [0, 8, 0, 10]])

        test4 = TP_Algos.VogelApproximationMethod(costs4, supply4, demand4)
        self.assertEqual(test4.totalCost, 12075)
        self.assertEqual(test4.allocated, [[200, 50, 0, 0], [0, 175, 0, 125], [0, 0, 275, 125]])
    

    def test_SSM(self):
        test1 = TP_Algos.SteppingStoneMethod(costs1, supply1, demand1)
        self.assertEqual(test1.totalCost, 2850)
        self.assertEqual(test1.allocated, [[0, 300, 0, 0], [250, 0, 150, 0], [0, 50, 250, 200]])

        test2 = TP_Algos.SteppingStoneMethod(costs2, supply2, demand2)
        self.assertEqual(test2.totalCost, 180)
        self.assertIn(test2.allocated, ([[20, 0, 10, 0], [0, 20, 20, 10], [0, 20, 0, 0]], 
                                        [[20, 10, 0, 0], [0, 10, 30, 10], [0, 20, 0, 0]]))
        
        test3 = TP_Algos.SteppingStoneMethod(costs3, supply3, demand3)
        self.assertEqual(test3.totalCost, 743)
        self.assertEqual(test3.allocated, [[5, 0, 0, 2], [0, 2, 7, 0], [0, 6, 0, 12]])

        test4 = TP_Algos.SteppingStoneMethod(costs4, supply4, demand4)
        self.assertEqual(test4.totalCost, 12075)
        self.assertIn(test4.allocated, ([[200, 50, 0, 0], [0, 175, 0, 125], [0, 0, 275, 125]], 
                                        [[25, 225, 0, 0], [175, 0, 0, 125], [0, 0, 275, 125]]))


    def test_MM(self):
        test1 = TP_Algos.MODIMethod(costs1, supply1, demand1)
        self.assertEqual(test1.totalCost, 2850)
        self.assertEqual(test1.allocated, [[0, 300, 0, 0], [250, 0, 150, 0], [0, 50, 250, 200]])

        test2 = TP_Algos.MODIMethod(costs2, supply2, demand2)
        self.assertEqual(test2.totalCost, 180)
        self.assertIn(test2.allocated, ([[20, 0, 10, 0], [0, 20, 20, 10], [0, 20, 0, 0]], 
                                        [[20, 10, 0, 0], [0, 10, 30, 10], [0, 20, 0, 0]]))
        
        test3 = TP_Algos.MODIMethod(costs3, supply3, demand3)
        self.assertEqual(test3.totalCost, 743)
        self.assertEqual(test3.allocated, [[5, 0, 0, 2], [0, 2, 7, 0], [0, 6, 0, 12]])

        test4 = TP_Algos.MODIMethod(costs4, supply4, demand4)
        self.assertEqual(test4.totalCost, 12075)
        self.assertIn(test4.allocated, ([[200, 50, 0, 0], [0, 175, 0, 125], [0, 0, 275, 125]], 
                                        [[25, 225, 0, 0], [175, 0, 0, 125], [0, 0, 275, 125]]))
        
           
if __name__ == '__main__':
    unittest.main()

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "common.hpp"
#include "utils.hpp"
#include "NorthWestCorner.hpp"
#include "LeastCostMethod.hpp"
#include "VogelApproximationMethod.hpp"
#include "SteppingStoneMethod.hpp"
#include "MODIMethod.hpp"

namespace py = pybind11;

PYBIND11_MODULE(TP_Algos, m)
{
    m.def("NorthWestCorner", &NorthWestCorner, R"pbdoc(
            Applies North West Corner Method to solve Transportation Problem.
        )pbdoc");

    m.def("LeastCostMethod", &LeastCostMethod, R"pbdoc(
            Applies Least Cost Method to solve Transportation Problem.
        )pbdoc");

    m.def("VogelApproximationMethod", &VogelApproximationMethod, R"pbdoc(
            Applies Vogel's Approximation Method to solve Transportation Problem.
        )pbdoc");

    m.def("SteppingStoneMethod", &SteppingStoneMethod, R"pbdoc(
            Applies Stepping Stone Method to solve Transportation Problem.
        )pbdoc");

    m.def("MODIMethod", &MODIMethod, R"pbdoc(
            Applies MODI Method to solve Transportation Problem.
        )pbdoc");

    py::class_<Ans>(m, "Ans")
        .def(py::init<const int, const int>())
        .def_readwrite("totalCost", &Ans::totalCost)
        .def_readwrite("allocated", &Ans::allocated);
        
    m.doc() = R"pbdoc(
           This module consists of the prominent algorithms for solving Transportation Problem.
    )pbdoc";
}

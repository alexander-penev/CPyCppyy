#ifndef CPYCPPYY_MEMORYREGULATOR_H
#define CPYCPPYY_MEMORYREGULATOR_H


namespace CPyCppyy {

    using namespace Cppyy;
    class CPPInstance;

    class MemoryRegulator {
    public:
        MemoryRegulator();

    // callback from C++-side frameworks
        static bool RecursiveRemove(TCppObject_t cppobj, TCppType_t klass);

    // add a python object to the table of managed objects
        static bool RegisterPyObject(CPPInstance* pyobj, void* cppobj);

    // remove a python object from the table of managed objects, w/o notification
        static bool UnregisterPyObject(TCppObject_t cppobj, TCppType_t klass);

    // new reference to python object matching cppobj, or 0 on failure
        static PyObject* RetrievePyObject(TCppObject_t cppobj, TCppType_t klass);

    // callback when weak refs to managed objects are destroyed
        static PyObject* EraseCallback(PyObject*, PyObject* pyref);
   };

} // namespace CPyCppyy

#endif // !CPYCPPYY_MEMORYREGULATOR_H

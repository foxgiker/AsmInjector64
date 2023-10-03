
#include <ntifs.h>
#include <ntddk.h>



void DriverUnload(PDRIVER_OBJECT  driverObject){
    UNREFERENCED_PARAMETER(driverObject);
}

NTSTATUS DriverEntry(PDRIVER_OBJECT  driverObject,PUNICODE_STRING registryPath){
    int status = STATUS_SUCCESS;
    DbgPrint("");
    driverObject->DriverUnload = DriverUnload;
    return status;
}



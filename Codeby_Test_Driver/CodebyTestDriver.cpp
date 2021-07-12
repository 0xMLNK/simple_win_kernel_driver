#include <ntddk.h>

void CodebyDriverUnload(_In_ PDRIVER_OBJECT DriverObject) {
	UNREFERENCED_PARAMETER(DriverObject);
	KdPrint(("CodebyDriverUnload called.\n"));

}

extern "C"
NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
) {
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	KdPrint(("Hi Codeby, this is our first driver! Yuhu!\n"));

	RTL_OSVERSIONINFOW info = { sizeof(info) };
	RtlGetVersion(&info);
	KdPrint(("Windows Version: %d.%d.%d  PlatformID: %d\n", info.dwMajorVersion, info.dwMinorVersion, info.dwBuildNumber, info.dwPlatformId ));
	
	DriverObject->DriverUnload = CodebyDriverUnload;

	return STATUS_SUCCESS;
}

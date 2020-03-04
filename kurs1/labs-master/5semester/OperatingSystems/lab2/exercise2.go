package main

import (
	"fmt"
	"syscall"
	"unsafe"
)

type systeminfo struct {
	wProcessorArchitecture      uint16
	wReserved                   uint16
	dwPageSize                  uint32
	lpMinimumApplicationAddress uintptr
	lpMaximumApplicationAddress uintptr
	dwActiveProcessorMask       uintptr
	dwNumberOfProcessors        uint32
	dwProcessorType             uint32
	dwAllocationGranularity     uint32
	wProcessorLevel             uint16
	wProcessorRevision          uint16
}

func main() {
	var sysinfo systeminfo
	procGetSystenInfo := syscall.NewLazyDLL("kernel32.dll").NewProc("GetSystemInfo")
	syscall.Syscall(procGetSystenInfo.Addr(), 1, uintptr(unsafe.Pointer(&sysinfo)), 0, 0)
	fmt.Println("number processor: ", sysinfo.dwNumberOfProcessors)
	fmt.Print("architecture processor: ")
	switch sysinfo.wProcessorArchitecture {
	case 0:
		fmt.Println("386")
	case 9:
		fmt.Println("amd64")
	case 5:
		fmt.Println("arm")
	case 12:
		fmt.Println("arm64")
	case 6:
		fmt.Println("Intel Itanium-based")
	default:
		fmt.Println("unknown")
	}
	fmt.Printf("pointer to the lowest memory address accessible to applications: 0x%X \n", sysinfo.lpMinimumApplicationAddress)
	fmt.Printf("pointer to the highest memory address accessible to applications: 0x%X \n", sysinfo.lpMaximumApplicationAddress)
}

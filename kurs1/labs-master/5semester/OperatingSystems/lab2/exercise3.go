package main

import (
	"fmt"
	"syscall"
	"unsafe"
)

type globalmemorystatus struct {
	dwLength                uint32
	dwMemoryLoad            uint32
	ullTotalPhys            uint64
	ullAvailPhys            uint64
	ullTotalPageFile        uint64
	ullAvailPageFile        uint64
	ullTotalVirtual         uint64
	ullAvailVirtual         uint64
	ullAvailExtendedVirtual uint64
}

func main() {
	procGlobalMemoryStatusEx := syscall.NewLazyDLL("kernel32.dll").NewProc("GlobalMemoryStatus")
	var memstatus globalmemorystatus
	syscall.Syscall(procGlobalMemoryStatusEx.Addr(), 1, uintptr(unsafe.Pointer(&memstatus)), 0, 0)
	fmt.Println("GlobalMemoryStatus: ", memstatus)
}

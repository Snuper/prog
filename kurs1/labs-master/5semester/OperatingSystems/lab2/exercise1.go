package main

import (
	"fmt"
	"golang.org/x/sys/windows"
	"syscall"
	"unicode/utf16"
	"unsafe"
)

func main() {
	var buflen uint32 = 64
	buf := make([]uint16, buflen)
	n, _ := windows.GetTempPath(buflen, &buf[0])

	fmt.Println("temp path: ", string(utf16.Decode(buf[:n])))

	procGetWindowsDirectory := syscall.NewLazyDLL("kernel32.dll").NewProc("GetWindowsDirectoryW")
	n_uptr, _, _ := syscall.Syscall(procGetWindowsDirectory.Addr(), 2, uintptr(unsafe.Pointer(&buf[0])), uintptr(buflen), 0)
	n = uint32(n_uptr)

	fmt.Println("windows directory: ", string(utf16.Decode(buf[:n])))
}

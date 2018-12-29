package main

import "C"
import (
	"encoding/binary"
	"fmt"
	"net"
	"sync"
	// "github.com/spieglt/flyingcarpet/core"
)

// necessary for compiling as a library
func main() {}

const toggleStartButton = 1 << 0
const showProgressBar = 1 << 1
const updateProgressBar = 1 << 2

// CppBridge sets up TCP sockets used to communicate with the wxWidgets C++ front end.
type CppBridge struct {
	CommandListener  *net.TCPListener
	OutputListener   *net.TCPListener
	TransferListener *net.TCPListener
	CommandConn      net.Conn
	OutputConn       net.Conn
	TransferConn     net.Conn
	mux              sync.Mutex
}

// Bridge is the global instance of CppBridge used to communicate between
// Flying Carpet's core package and the wxWidgets C++ GUI front end
var Bridge = CppBridge{}

// Gui fulfills the UI interface to be used in the core functions.
type Gui struct{}

// Output prints messages to the output box. It just wraps the C-exported GoOutput().
func (gui Gui) Output(message string) {
	GoOutput(message)
}

// ShowProgressBar displays the progress bar in the GUI when the transfer starts.
func (gui Gui) ShowProgressBar() {
	SendCommand(showProgressBar)
}

// UpdateProgressBar prints the status of a file transfer.
func (gui Gui) UpdateProgressBar(percentDone int) {
	SendCommand(updateProgressBar)
}

// ToggleStartButton flips it between "Start" and "Cancel" in the GUI.
func (gui Gui) ToggleStartButton() {
	SendCommand(toggleStartButton)
}

func SendCommand(command int) {
	Bridge.mux.Lock()
	defer Bridge.mux.Unlock()
	Bridge.CommandConn.Write([]byte{byte(command)})
}

//export GoOutput
func GoOutput(message string) {
	Bridge.mux.Lock()
	defer Bridge.mux.Unlock()
	err := binary.Write(Bridge.OutputConn, binary.BigEndian, len(message))
	if err != nil {
		panic(fmt.Errorf("Error sending message length length: %s", err))
	}
	_, err = Bridge.OutputConn.Write([]byte(message))
	if err != nil {
		panic(fmt.Errorf("Error sending message to GUI: %s", err))
	}
}

func getInput() {
	// listen on TransferConn for information

}

//export SetupCommandListener
func SetupCommandListener() int {
	var err error
	Bridge.CommandListener, err = net.ListenTCP("tcp", &net.TCPAddr{
		IP:   net.IPv4(127, 0, 0, 1),
		Port: 0,
	})
	if err != nil {
		fmt.Printf("Could not set up command listener: %s\n", err.Error())
		return 0
	}
	go func() {
		var err error
		Bridge.CommandConn, err = Bridge.CommandListener.Accept()
		if err != nil {
			fmt.Printf("Could not set up command connection: %s\n", err.Error())
		}
	}()
	return Bridge.CommandListener.Addr().(*net.TCPAddr).Port
}

//export CloseCommandListener
func CloseCommandListener() {
	Bridge.CommandConn.Close()
	Bridge.CommandListener.Close()
}

//export SetupOutputListener
func SetupOutputListener() int {
	var err error
	Bridge.OutputListener, err = net.ListenTCP("tcp", &net.TCPAddr{
		IP:   net.IPv4(127, 0, 0, 1),
		Port: 0,
	})
	if err != nil {
		fmt.Printf("Could not set up output listener. Err: %s\n", err)
		return 0
	}
	go func() {
		var err error
		Bridge.OutputConn, err = Bridge.OutputListener.Accept()
		if err != nil {
			fmt.Printf("Could not set up output connection: %s\n", err.Error())
		}
	}()
	return Bridge.OutputListener.Addr().(*net.TCPAddr).Port
}

//export CloseOutputListener
func CloseOutputListener() {
	Bridge.OutputConn.Close()
	Bridge.OutputListener.Close()
}

//export SetupTransferListener
func SetupTransferListener() int {
	var err error
	Bridge.TransferListener, err = net.ListenTCP("tcp", &net.TCPAddr{
		IP:   net.IPv4(127, 0, 0, 1),
		Port: 0,
	})
	if err != nil {
		fmt.Printf("Could not set up Transfer listener. Err: %s\n", err)
		return 0
	}
	go func() {
		var err error
		Bridge.TransferConn, err = Bridge.TransferListener.Accept()
		if err != nil {
			fmt.Printf("Could not set up Transfer connection: %s\n", err.Error())
		}
	}()
	return Bridge.TransferListener.Addr().(*net.TCPAddr).Port
}

//export CloseTransferListener
func CloseTransferListener() {
	Bridge.TransferConn.Close()
	Bridge.TransferListener.Close()
}

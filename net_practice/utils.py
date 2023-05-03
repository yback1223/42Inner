def to_bin(arr):
	for i in range(len(arr)):
		arr[i] = bin(arr[i])
	return arr

def calculate_Network_address(IP, Mask):
	Network = []
	for i in range(len(IP)):
		Network.append(int(IP[i], 2) & int(Mask[i], 2))
	return Network

def invert_bin(num):
	inverted_integer = ~num
	inverted_binary_string = bin(inverted_integer & ((1 << num.bit_length()) - 1))
	return inverted_binary_string

def calculate_Broadcast_address(IP, Mask):
	Broadcast = []
	for i in range(len(IP)):
		Broadcast.append(int(IP[i], 2) | int(invert_bin(int(Mask[i], 2)), 2))
	return Broadcast

def print_address(msg, arr):
	print(f"{msg}: ", end = "")
	for i in range(len(arr)):
		print(arr[i], end = "")
		if i != len(arr) - 1:
			print(".", end = "")
	print()

while True:
	IP_address = list(map(int, input("IP: ").split('.')))
	Subnet_Mask = list(map(int, input("Mask: ").split('.')))

	IP_bin = to_bin(IP_address)
	Mask_bin = to_bin(Subnet_Mask)
	Network_bin = calculate_Network_address(IP_bin, Mask_bin)
	Broadcast_bin = calculate_Broadcast_address(IP_bin, Mask_bin)

	print_address("Network", Network_bin)
	print_address("Broadcast", Broadcast_bin)
	print("========================")


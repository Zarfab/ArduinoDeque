# ArduinoDeque
Defines a templated (generic) class for a double-ended queue of things.
This code is a modifiation from [Arduino-Queue](https://github.com/sdesalas/Arduino-Queue.h) by Steven de Salas. See his well written readme for more information.

Tested on Arduino Uno and ESP32

## Constructor

### `Deque<T> queue = Deque<T>(int maxlength = 256);`

Creates a double-ended queue of a generic type `T` with a maximum queue size. If `maxlength` is not defined it will default to 256.

NOTE: If the queue grows to `maxlength` items (and you dont take them out) any additional items added *will drop out of the queue*.
Please bear this in mind when defining maxlength so it is a reasonable balance between RAM usage and functional usefulness.

## Methods

### `queue.push_back(T item);`

Adds a generic item (of `T` type) at the back of the queue.

### `queue.push_front(T item);`

Adds a generic item (of `T` type) at the front of the queue.

### `T item = queue.pop_back();`

Gets a generic item (of `T` type) from the back of the queue. 

### `T item = queue.pop_front();`

Gets a generic item (of `T` type) from the front of the queue. 

### `T item = queue.peek_back();`

Same as .pop_back() but keeps the item in the queue.

### `T item = queue.peek_front();`

Same as .pop_front() but keeps the item in the queue.

### `T item = queue[int i];`

Get the item at index i in the queue. The item will be kept in the queue. If the index is out of bound, an empty item is returned.

### `queue[int i] = T item;`

Set the item at index i in the queue. If the index is out of bound, nothing happens.

### `int count = queue.count();`

Gets the current number of elements in the queue.

### `queue.clear();`

Clears the queue but does not free memory used to store data.

### `T* items = queue.to_array();`

Returns items in the queue as an array.

### `int front = queue.front();`

Gets the current position in the front of the queue. Used for testing queue logic.

### `int back = queue.back();`

Gets the current position at the back of the queue. Used for testing queue logic.

### `T* data = queue.data_array();`

Returns all values from data allocated memory. Used for testing queue logic.

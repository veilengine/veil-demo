# Veil-Demo

This is a simple demo showcasing the [Veil](http://github.com/veilengine/veil) game development framework using the sdl extension. Eventually there will be extensions for using GL or GLES.

### Usage

Presently, Veil is only tested on Linux. I'll be testing it on OSX soon.

First, you'll need SDL2, SDL2_image, SDL2_ttf and libuv installed.

```
sudo apt-get install libuv-dev libsdl2-dev libsdl2-image-dev  libsdl2-mixer-dev libsdl2-ttf-dev -y
```

Next, we need to check out the repos. This demo currently assumes it's in the same path as the veil core and sdl libraries.

```
mkdir veil
cd veil
git clone git@github.com:veilengine/veil.git
git clone git@github.com:veilengine/veil-sdl.git
git clone git@github.com:veilengine/veil-demo.git
cd veil-demo
```

Now we can just use `make` to build and run the demo.

```
make run
```
---

### Copyright (c) 2014 Stephen Belanger
#### Licensed under MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

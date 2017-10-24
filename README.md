[![Build Status](https://secure.travis-ci.org/NickolasVashchenko/stopgap_13632.svg)](http://travis-ci.org/NickolasVashchenko/stopgap_13632)
[![Build Status](https://ci.appveyor.com/api/projects/status/cqgu4tce6of44c9x?svg=true)](https://ci.appveyor.com/api/projects/status/cqgu4tce6of44c9x?svg=true)

## Disclaimer
As on 24.10.2017 the bug has been fixed in 2.3.5, 2.4.2 and in trunk. Please, update your interpreter.

## Description
A gem with a temporary stopgap workaround for MRI Ruby for the bug https://bugs.ruby-lang.org/issues/13632 until the proper fix gets backported.
There are 4 versions affected 2.2.7, 2.2.8, 2.3.4, 2.4.1.


## How does this bug look?
You're getting a similar exception erratically in a presence of many threads:
```ruby
Traceback (most recent call last):
    1: from test2.rb:9:in `block (2 levels) in <main>'
test2.rb:9:in `sysopen': stream closed in another thread (IOError)
```

## Installation and usage
In Gemfile:
```ruby
if %w(2.2.7 2.2.8 2.3.4 2.4.1).include? RUBY_VERSION
  gem "stopgap_13632", "~> 1.0", :platforms => ["mri", "mingw", "x64_mingw"]
end

```
Don't forget to require it:
```
require 'stopgap_13632'
```
And when an "IOError: stream closed" happens in a thread, accessing a busy IO, catch it and call the following method:
```
rescue IOError
  Thread.current.purge_interrupt_queue
end
```
It will unblock the thread and allow it to proceed.

## Contributing
```bash
rake compile
rake test
```

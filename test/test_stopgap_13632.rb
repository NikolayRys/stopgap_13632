require 'minitest/autorun'
require_relative '../lib/stopgap_13632'

Thread.abort_on_exception = true

class Stopgap13632Test < Minitest::Test

  def test_concurrent_io_access
    pipes = []
    threads = []
    100.times do
      r, w = IO.pipe
      pipes << [r, w]
      threads << Thread.new do
        while r.gets
        end rescue IOError
        if Thread.current.pending_interrupt?
          assert Thread.current.respond_to? (:purge_interrupt_queue), "The bug detected for version #{RUBY_VERSION}"
          Thread.current.purge_interrupt_queue
          assert !Thread.current.pending_interrupt?, 'Workaround failed'
        end
      end
    end
    pipes.each do |r, w|
      w.puts 'test'
      w.close
      r.close
    end
    threads.each do |th|
      th.join
    end
  end

end

require 'rake/extensiontask'
require 'rake/testtask'

spec = Gem::Specification.load('stopgap_13632.gemspec')
Rake::ExtensionTask.new('stopgap_13632', spec)

Rake::TestTask.new do |t|
  t.pattern = 'test/test_*.rb'
end

Gem::Specification.new do |s|
  s.name = 'stopgap_13632'
  s.version = '1.1.2'
  s.authors = ['Nikolay Vashchenko']
  s.description = 'Temporary stopgap workaround for MRI Ruby versions 2.2.7, 2.2.8, 2.2.9, 2.2.10, 2.3.4, 2.4.1 for the bug https://bugs.ruby-lang.org/issues/13632 until it gets backported'
  s.summary = 'Temporary solution for https://bugs.ruby-lang.org/issues/13632'
  s.email = 'sir.nickolas@gmail.com'
  s.extensions = ['ext/stopgap_13632/extconf.rb']
  s.files = `git ls-files`.split($/)
  s.homepage = 'https://github.com/NickolasVashchenko/stopgap_13632'
  s.license = 'MIT'
  s.required_ruby_version = '> 2.2.6', '< 2.4.2'
  s.add_development_dependency 'rake-compiler', '~> 1.0'
  s.add_development_dependency 'minitest', '~> 5.8'
end

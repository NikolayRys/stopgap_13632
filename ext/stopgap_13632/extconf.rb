require 'mkmf'

extension_name = 'stopgap_13632'

dir_config(extension_name)

BROKEN_VERSIONS = %w(2.2.7 2.2.8 2.2.9 2.2.10 2.3.4 2.4.1)
if (BROKEN_VERSIONS.include? RUBY_VERSION)
  $defs << '-DBROKEN_RUBY'
  $defs << "-DVERSION_#{RUBY_VERSION.gsub('.', '_')}"
end

create_makefile(extension_name )

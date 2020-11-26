#
# define transport authorization callback, provide username & password interactively
#

module Openwsman
  class Transport
      def Transport.auth_request_callback( client, auth_type )
	puts "Transport.auth_request_callback( #{client}, #{auth_type} )"
	puts Transport.auth_name( auth_type )
	puts "#{Transport.auth_name( auth_type )} authentication failed for #{client.host}"
	print "Username:"
	STDOUT.flush
	username = STDIN.gets.chomp
	print "Password:"
	STDOUT.flush
	password = STDIN.gets.chomp
	return [ username, password ]
      end
  end
end

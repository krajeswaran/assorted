# Prints the number commits of a user on github(or company hosted github) over six months.
# Useful when you've used different SSH keys to commit or your key's email doesn't match github profile
require 'nokogiri'
require 'open-uri'
require 'active_support/core_ext'
require 'date'

doc = Nokogiri.parse(open('https://github.com/<username>.atom'))
doc.remove_namespaces!

doc.slop!

count = 0
doc.xpath('//published').each do |x|
  parse = DateTime.parse(x.content)
  if parse > (Time.now - 6.month)
    count += 1
  end
end

print count



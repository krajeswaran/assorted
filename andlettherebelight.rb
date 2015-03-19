# Populates two flat tables with fake users with fake addresses and fake transactions for each user.
# Especially useful in generating fake, but realistic data for analysing data technologies like BigData, NoSQL and RDBMS.

require 'ffaker'

N = 20_000 #no of users
M = 20 #no of transactions per user

File.new("users.txt")
File.new("transactions.txt")

def create_user_transactions()
  open("users.txt", "a+") { |u|

  # create user id
  o =  (0..9).map{|i| i}.flatten; 
  user_id  =  (0..20).map{ o[rand(o.length)] }.join;
  fname = Faker::Name.first_name
  lname = Faker::Name.last_name
  zip= Faker::AddressUS.zip_code

  open("transactions.txt", "a+") { |f|
    M.times do |i|
      prod = Faker::HipsterIpsum.word
      f.puts "#{user_id}#{i}\t#{user_id}\t#{prod}"
      puts "#{user_id}#{i}\t#{user_id}\t#{prod}"
    end
  }

  u.puts "#{user_id}\t#{fname} #{lname}\t#{zip}"
  puts "#{user_id}\t#{fname} #{lname}\t#{zip}"
  #print user.to_s
  #readline
  }
end

N.times do
  create_user_transactions()
end


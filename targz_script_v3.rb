# Script to extract .tar.gz files - see prev versions for enlightenment
# https://stackoverflow.com/questions/856891/unzip-zip-tar-tag-gz-files-with-ruby
require 'rubygems/package'
require 'zlib'
require 'pathname'

(5..15).each do |n|
  num = n.to_s
  num = "0#{num}" if num.length == 1
  filename = "shooter#{num}.tar.gz"
  tar_extract = Gem::Package::TarReader.new(Zlib::GzipReader.open(filename))

  tar_extract.each do |entry|
    File.open(entry.full_name, 'wb') { |f| f.write(entry.read) } if entry.file?
    if entry.directory?
      begin
        Dir.mkdir(entry.full_name)
      rescue Errno::EEXIST
        puts "Directory #{entry.full_name} exists, continue? (y/n)"
        input = gets.chomp
        exit unless input.start_with?('y')
      end
    end

    puts "extracting #{entry.full_name}"
  end
  tar_extract.close
end

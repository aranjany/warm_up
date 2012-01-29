#!/usr/bin/perl -w
use strict;

use File::Find;



my $dir= '.';

find (\&doone, $dir);

sub doone
{

my $file = $_;
my $line;

open(TXT, $file);
while($line = <TXT>)
{
print "$line" if $line =~/test/
}
close TXT;

}


#print "\n$file" if -d $file

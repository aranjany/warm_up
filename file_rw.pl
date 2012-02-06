#!/usr/bin/perl -w
use strict;

use File::Find;



my $dir= 'C:/Test/LOOK';

#find (\&donext, $dir);

#find (\&doone, $dir);
my $ newdir = "C:/Test/LOOK";

find(\&dotest,$newdir);






sub doone
{

my $file = $_;
my $line;

open(TXT, $file);
while($line = <TXT>)
{
print "$line" if $line =~ /pass/
}
close TXT;

}





sub donext
{

my $myfile = $_;
print $myfile;
print " \n" ;
my $line;

open (TXT, "+<C:/Test/LOOK/tolook.txt" );
my @file1 = <TXT>;

seek TXT,0,0;

foreach $line(@file1)
{
$line =~ s/pass/padd/g;
print TXT $line;

}

close TXT;

}





sub dotest
{

my $file = $_;

if( -T $file)
{


open (TXT, "+<$file");

my @file = <TXT>;
my $line;

foreach $line (@file)
{

if( $line =~ /^\s*$/)
{
print "Blank line";

}
else
{
print TXT "\n New Line here\n";
}
}
close TXT;
}

}


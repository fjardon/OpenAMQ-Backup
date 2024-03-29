
%define apuver 1

Summary: Apache Portable Runtime Utility library
Name: apr-util
Version: 1.2.2
Release: 1
License: Apache Software License
Group: System Environment/Libraries
URL: http://apr.apache.org/
Source0: %{name}-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-buildroot
BuildPrereq: autoconf, libtool, doxygen, apr-devel >= 0:{version}-{release}
BuildPrereq: openldap-devel, db4-devel, expat-devel
Conflicts: subversion < 0.20.1-2

%description
The mission of the Apache Portable Runtime (APR) is to provide a
free library of C data structures and routines.  This library
contains additional utility interfaces for APR; including support
for XML, LDAP, database interfaces, URI parsing and more.

%package devel
Group: Development/Libraries
Summary: APR utility library development kit
Requires: apr-util = %{version}-%{release}, apr-devel
Requires: openldap-devel, db4-devel, expat-devel
Conflicts: subversion-devel < 0.20.1-2

%description devel
This package provides the support files which can be used to 
build applications using the APR utility library.  The mission 
of the Apache Portable Runtime (APR) is to provide a free 
library of C data structures and routines.

%prep
%setup -q

%build
%configure --with-apr=%{_prefix} \
        --includedir=%{_includedir}/apr-%{apuver} \
        --with-ldap --without-gdbm
make %{?_smp_mflags} && make dox

%check
# Run non-interactive tests
pushd test
make %{?_smp_mflags} testall CFLAGS=-fno-strict-aliasing
./testall -v || exit 1
popd

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT

# Documentation
mv docs/dox/html html

# Unpackaged files
rm -f $RPM_BUILD_ROOT%{_libdir}/aprutil.exp

%clean
rm -rf $RPM_BUILD_ROOT

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%doc CHANGES LICENSE NOTICE
%{_libdir}/libaprutil-%{apuver}.so.*

%files devel
%defattr(-,root,root,-)
%{_bindir}/apu-%{apuver}-config
%{_libdir}/libaprutil-%{apuver}.*a
%{_libdir}/libaprutil-%{apuver}.so
%{_libdir}/pkgconfig/apr-util-%{apuver}.pc
%{_includedir}/apr-%{apuver}/*.h
%doc --parents html

%changelog
* Tue Jun 22 2004 Graham Leggett <minfrin@sharp.fm> 1.0.0-1
- update to support v1.0.0 of APR
                                                                                
* Tue Jun 22 2004 Graham Leggett <minfrin@sharp.fm> 1.0.0-1
- derived from Fedora Core apr.spec


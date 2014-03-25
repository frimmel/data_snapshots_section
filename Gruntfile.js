module.exports = function(grunt) {

    // Project configuration.
    grunt.initConfig({
	    pkg: grunt.file.readJSON('package.json'),
	    banner: '/*! <%= pkg.name %>\n' +
	        ' * Copyright 2014 University of North Carolina at Asheville\n' +
           	' * Released under the MIT license\n' +
	        ' */',
	    concat: {
		    dataSnapshotJs: {
		        src: [
			        "modules/data_snapshots/js/data-snapshots.js"
		        ],
		        dest: 'modules/data_snapshots/build/data-snapshots.js'
		    },
		    dataSnapshotCss: {
		        src: [
			        "modules/data_snapshots/css/data-snapshots.css"
                ],
		        dest: 'modules/data_snapshots/build/data-snapshots.css'
		    }
	    },
	    uglify: {
		    options: {
		        banner: '<%= banner %>' + '\n'
		    },
		    build: {
		        src: 'modules/data_snapshots/build/data-snapshots.js',
		        dest: 'modules/data_snapshots/build/data-snapshots.min.js'
		    }
	    },
	    cssmin: {
		    dataSnapshotCss: {
		        options: {
			        keepSpecialComments: 0,
			        banner: '<%= banner %>'
		        },
                src: "modules/data_snapshots/build/data-snapshots.css",
                dest: "modules/data_snapshots/build/data-snapshots.min.css"
            }
	    }
	});

    grunt.loadNpmTasks('grunt-contrib-concat');
    grunt.loadNpmTasks('grunt-contrib-uglify');
    grunt.loadNpmTasks('grunt-contrib-cssmin');

    // Default task(s).
    grunt.registerTask('default', ['concat', 'uglify', 'cssmin']);
};

# Utility that reads a template file in Jinja format, a substitutions dictionary
# in json format, and writes the rendered text to a file.

# To use, run
# template_renderer <template file> <output file> <substitutions>


import jinja2
import json
import sys


# Reads a template, renders it, and writes the output to a file.
#
# The template is provided in a text file in Jinja format
# (https://jinja.palletsprojects.com/), and the substitutions are provided in
# json format.
#
# Crashes if either any of the required arguments is not provided in the command
# line, or if anything else is provided in the command line.
#
# Args (these are taken from the command line, i.e. sys.argv):
# - template_filename (sys.argv[1]): The name of the file that contains the
#   template to be rendered
# - output_filename (sys.argv[2]): The name of the file to which the rendered
#   template will be written
# - substitutions (sys.argv[3]): A json representation of a dictionary with the
#   variables and names to be substituted while rendering the provided template
def main() -> int:
    # Read parameters
    num_parameters = len(sys.argv)
    assert num_parameters == 4
    template_filename = sys.argv[1]
    output_filename = sys.argv[2]
    substitutions = json.loads(sys.argv[3])

    # Read template file
    template_file = open(template_filename, "r")
    template_str = template_file.read()
    template_file.close()

    # Render template
    template = jinja2.Environment().from_string(template_str)
    rendered_str = template.render(substitutions)

    # Write output to desired file
    output_file = open(output_filename, "w")
    output_file.write(rendered_str)
    output_file.close()

    return 0


if __name__ == '__main__':
    sys.exit(main())
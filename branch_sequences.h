/*
 *  Wellcome Trust Sanger Institute
 *  Copyright (C) 2011  Wellcome Trust Sanger Institute
 *  
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _BRANCH_SEQUENCES_H_
#define _BRANCH_SEQUENCES_H_

char *generate_branch_sequences(newick_node *root, FILE *vcf_file_pointer,int * snp_locations, int number_of_snps, char** column_names, int number_of_columns, char reference_bases, char * leaf_sequence, int length_of_original_genome);
int calculate_number_of_snps_excluding_gaps(char * ancestor_sequence, char * child_sequence, int child_sequence_size, int * branch_snp_coords, int * snp_locations);
void identify_recombinations(int number_of_branch_snps, int * branches_snp_sites,int length_of_original_genome);
double calculate_snp_density(int * branches_snp_sites, int number_of_branch_snps, int index);
int calculate_size_of_genome_without_gaps(char * child_sequence, int start_index,int length_of_sequence,  int length_of_original_genome);
void get_likelihood_for_windows(char * child_sequence, int length_of_sequence, int * snp_site_coords,int branch_genome_size, int number_of_branch_snps);
double get_block_likelihood(int branch_genome_size, int number_of_branch_snps, int block_genome_size_without_gaps, int number_of_block_snps);

#define MIN_SNPS_FOR_IDENTIFYING_RECOMBINATIONS 10
#define DEFAULT_SNP_DENSITY 0.000001
#define MAX_WINDOW 1000
#define WINDOW_SIZE 10

#endif